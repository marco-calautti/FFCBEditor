#include "CBTextArchive.h"
#include "CBTextArchiveSection.h"

#include <wx/wfstream.h>
#include <wx/mstream.h>

CBTextArchive::CBTextArchive(wxInputStream &input)
{
	Initialize(input);
}

CBTextArchive::CBTextArchive(wxString &fileName)
{
	wxFileInputStream stream(fileName);
	Initialize(stream);
}

CBTextArchive::CBTextArchive(const wxChar* fileName)
{
	wxFileInputStream stream(fileName);
	Initialize(stream);
}

CBTextArchive::~CBTextArchive()
{
	if(sections){
		for(size_t i=0;i<size;i++)
			delete sections[i];
		delete[] sections;
	}
}

void CBTextArchive::Initialize(wxInputStream &input)
{
	wxFileOffset len=input.GetLength();
	wxByte* buffer=new wxByte[len];
	input.Read(buffer,len);
	
	size=wxINT32_SWAP_ON_LE(*((wxUint32*)buffer))/(sizeof(wxUint32)*2);
	sections=new CBTextSection*[size];
	wxUint32* secondHeader=&(((wxUint32*)buffer)[size]);

	for(size_t i=0;i<size;i++){
		//current text section position
		wxUint32 pos=wxINT32_SWAP_ON_LE(((wxUint32*)buffer)[i]);
		wxUint32 numPointers=wxINT32_SWAP_ON_LE(secondHeader[i]);
		sections[i]=new CBTextArchiveSection(&buffer[pos],numPointers);
	}

	delete[] buffer;
}

size_t CBTextArchive::Size()
{
	return size;
}

CBTextSection* CBTextArchive::operator [](size_t i)
{
	return sections[i];
}

int CBTextArchive::SaveTo(wxString& fileName)
{
	wxFileOutputStream stream(fileName);
	return SaveTo(stream);
}

int CBTextArchive::SaveTo(const wxChar* fileName)
{
	wxFileOutputStream stream(fileName);
	return SaveTo(stream);
}

int CBTextArchive::SaveTo(wxOutputStream& output)
{
	wxUint32* pointersBuf=new wxUint32[size]; //text blocks pointers buffer
	wxUint32* numPointersBuf=new wxUint32[size]; //second header block buffer
	wxMemoryOutputStream outBuf;

	wxUint32 curPos=size*2*sizeof(wxUint32);

	for(size_t i=0;i<size;i++){
		wxUint32 sectionSize;
		char* writableBuffer=sections[i]->GetWritableBuffer(&sectionSize);
		outBuf.Write(writableBuffer,sectionSize);
		sections[i]->FreeBuffer();
		pointersBuf[i]=wxINT32_SWAP_ON_LE(curPos);
		numPointersBuf[i]=wxINT32_SWAP_ON_LE(sections[i]->Size());
		curPos+=sectionSize;
	}

	output.Write(pointersBuf,size*sizeof(wxUint32));
	output.Write(numPointersBuf,size*sizeof(wxUint32));

	

	output.Write(outBuf.GetOutputStreamBuffer()->GetBufferStart(),outBuf.GetLength());

	delete[] pointersBuf;
	delete[] numPointersBuf;

	return 0;
}