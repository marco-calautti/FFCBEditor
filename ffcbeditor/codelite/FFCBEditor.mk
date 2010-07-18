##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release_Windows
ProjectName            :=FFCBEditor
ConfigurationName      :=Release_Windows
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "D:\Documenti\CodeLite Projects\workspace"
ProjectPath            := "D:\Documenti\CodeLite Projects\workspace\FFCBEditor"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=07/18/10
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=./workingdir/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)__WX__ 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=
MakeDirCommand         :=makedir
CmpOptions             := -O2 $(shell wx-config --cxxflags --unicode=yes --debug=no) $(Preprocessors)
RcCmpOptions           := $(shell wx-config --rcflags)
RcCompilerName         :=windres
LinkOptions            :=  -mwindows -s $(shell wx-config --debug=no --libs --unicode=yes)
IncludePath            :=  "$(IncludeSwitch)." 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
WXCFG:=gcc_lib\mswu
WXWIN:=C:\wxWidgets-2.8.9
Objects=src/cblib/$(IntermediateDirectory)/CBSingleFile$(ObjectSuffix) src/cblib/$(IntermediateDirectory)/CBSingleFileTextSection$(ObjectSuffix) src/cblib/$(IntermediateDirectory)/CBTextArchive$(ObjectSuffix) src/cblib/$(IntermediateDirectory)/CBTextArchiveSection$(ObjectSuffix) src/cblib/$(IntermediateDirectory)/CBFREBArchive$(ObjectSuffix) src/cblib/$(IntermediateDirectory)/CBEEVBFile$(ObjectSuffix) src/cblib/$(IntermediateDirectory)/CBEEVBTextSection$(ObjectSuffix) src/common/$(IntermediateDirectory)/ConfigManager$(ObjectSuffix) src/common/$(IntermediateDirectory)/DBManager$(ObjectSuffix) src/common/$(IntermediateDirectory)/FileManager$(ObjectSuffix) \
	src/gui/$(IntermediateDirectory)/CBItemData$(ObjectSuffix) src/gui/$(IntermediateDirectory)/FFCBMainFrame$(ObjectSuffix) src/gui/$(IntermediateDirectory)/FFCBPreferencesDialog$(ObjectSuffix) src/gui/$(IntermediateDirectory)/FFCBPreviewDialog$(ObjectSuffix) src/gui/$(IntermediateDirectory)/FFCBSingleFilePanel$(ObjectSuffix) src/gui/$(IntermediateDirectory)/FFCBDropTarget$(ObjectSuffix) src/gui/$(IntermediateDirectory)/FFCBTextArchivePanelBase$(ObjectSuffix) src/gui/$(IntermediateDirectory)/FFCBTextArchivePanel$(ObjectSuffix) src/gui/$(IntermediateDirectory)/cbgui$(ObjectSuffix) src/gui/$(IntermediateDirectory)/FFCBEEVBFilePanel$(ObjectSuffix) \
	src/gui/$(IntermediateDirectory)/FFCBTextCtrl$(ObjectSuffix) src/$(IntermediateDirectory)/app$(ObjectSuffix) $(IntermediateDirectory)/resource.rc$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
src/cblib/$(IntermediateDirectory)/CBSingleFile$(ObjectSuffix): src/cblib/CBSingleFile.cpp src/cblib/$(IntermediateDirectory)/CBSingleFile$(DependSuffix)
	@$(MakeDirCommand) "src/cblib/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBSingleFile.cpp" $(CmpOptions) $(ObjectSwitch)src/cblib/$(IntermediateDirectory)/CBSingleFile$(ObjectSuffix) $(IncludePath)
src/cblib/$(IntermediateDirectory)/CBSingleFile$(DependSuffix): src/cblib/CBSingleFile.cpp
	@$(MakeDirCommand) "src/cblib/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/cblib/$(IntermediateDirectory)/CBSingleFile$(ObjectSuffix) -MFsrc/cblib/$(IntermediateDirectory)/CBSingleFile$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBSingleFile.cpp"

src/cblib/$(IntermediateDirectory)/CBSingleFileTextSection$(ObjectSuffix): src/cblib/CBSingleFileTextSection.cpp src/cblib/$(IntermediateDirectory)/CBSingleFileTextSection$(DependSuffix)
	@$(MakeDirCommand) "src/cblib/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBSingleFileTextSection.cpp" $(CmpOptions) $(ObjectSwitch)src/cblib/$(IntermediateDirectory)/CBSingleFileTextSection$(ObjectSuffix) $(IncludePath)
src/cblib/$(IntermediateDirectory)/CBSingleFileTextSection$(DependSuffix): src/cblib/CBSingleFileTextSection.cpp
	@$(MakeDirCommand) "src/cblib/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/cblib/$(IntermediateDirectory)/CBSingleFileTextSection$(ObjectSuffix) -MFsrc/cblib/$(IntermediateDirectory)/CBSingleFileTextSection$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBSingleFileTextSection.cpp"

src/cblib/$(IntermediateDirectory)/CBTextArchive$(ObjectSuffix): src/cblib/CBTextArchive.cpp src/cblib/$(IntermediateDirectory)/CBTextArchive$(DependSuffix)
	@$(MakeDirCommand) "src/cblib/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBTextArchive.cpp" $(CmpOptions) $(ObjectSwitch)src/cblib/$(IntermediateDirectory)/CBTextArchive$(ObjectSuffix) $(IncludePath)
src/cblib/$(IntermediateDirectory)/CBTextArchive$(DependSuffix): src/cblib/CBTextArchive.cpp
	@$(MakeDirCommand) "src/cblib/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/cblib/$(IntermediateDirectory)/CBTextArchive$(ObjectSuffix) -MFsrc/cblib/$(IntermediateDirectory)/CBTextArchive$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBTextArchive.cpp"

src/cblib/$(IntermediateDirectory)/CBTextArchiveSection$(ObjectSuffix): src/cblib/CBTextArchiveSection.cpp src/cblib/$(IntermediateDirectory)/CBTextArchiveSection$(DependSuffix)
	@$(MakeDirCommand) "src/cblib/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBTextArchiveSection.cpp" $(CmpOptions) $(ObjectSwitch)src/cblib/$(IntermediateDirectory)/CBTextArchiveSection$(ObjectSuffix) $(IncludePath)
src/cblib/$(IntermediateDirectory)/CBTextArchiveSection$(DependSuffix): src/cblib/CBTextArchiveSection.cpp
	@$(MakeDirCommand) "src/cblib/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/cblib/$(IntermediateDirectory)/CBTextArchiveSection$(ObjectSuffix) -MFsrc/cblib/$(IntermediateDirectory)/CBTextArchiveSection$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBTextArchiveSection.cpp"

src/cblib/$(IntermediateDirectory)/CBFREBArchive$(ObjectSuffix): src/cblib/CBFREBArchive.cpp src/cblib/$(IntermediateDirectory)/CBFREBArchive$(DependSuffix)
	@$(MakeDirCommand) "src/cblib/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBFREBArchive.cpp" $(CmpOptions) $(ObjectSwitch)src/cblib/$(IntermediateDirectory)/CBFREBArchive$(ObjectSuffix) $(IncludePath)
src/cblib/$(IntermediateDirectory)/CBFREBArchive$(DependSuffix): src/cblib/CBFREBArchive.cpp
	@$(MakeDirCommand) "src/cblib/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/cblib/$(IntermediateDirectory)/CBFREBArchive$(ObjectSuffix) -MFsrc/cblib/$(IntermediateDirectory)/CBFREBArchive$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBFREBArchive.cpp"

src/cblib/$(IntermediateDirectory)/CBEEVBFile$(ObjectSuffix): src/cblib/CBEEVBFile.cpp src/cblib/$(IntermediateDirectory)/CBEEVBFile$(DependSuffix)
	@$(MakeDirCommand) "src/cblib/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBEEVBFile.cpp" $(CmpOptions) $(ObjectSwitch)src/cblib/$(IntermediateDirectory)/CBEEVBFile$(ObjectSuffix) $(IncludePath)
src/cblib/$(IntermediateDirectory)/CBEEVBFile$(DependSuffix): src/cblib/CBEEVBFile.cpp
	@$(MakeDirCommand) "src/cblib/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/cblib/$(IntermediateDirectory)/CBEEVBFile$(ObjectSuffix) -MFsrc/cblib/$(IntermediateDirectory)/CBEEVBFile$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBEEVBFile.cpp"

src/cblib/$(IntermediateDirectory)/CBEEVBTextSection$(ObjectSuffix): src/cblib/CBEEVBTextSection.cpp src/cblib/$(IntermediateDirectory)/CBEEVBTextSection$(DependSuffix)
	@$(MakeDirCommand) "src/cblib/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBEEVBTextSection.cpp" $(CmpOptions) $(ObjectSwitch)src/cblib/$(IntermediateDirectory)/CBEEVBTextSection$(ObjectSuffix) $(IncludePath)
src/cblib/$(IntermediateDirectory)/CBEEVBTextSection$(DependSuffix): src/cblib/CBEEVBTextSection.cpp
	@$(MakeDirCommand) "src/cblib/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/cblib/$(IntermediateDirectory)/CBEEVBTextSection$(ObjectSuffix) -MFsrc/cblib/$(IntermediateDirectory)/CBEEVBTextSection$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/cblib/CBEEVBTextSection.cpp"

src/common/$(IntermediateDirectory)/ConfigManager$(ObjectSuffix): src/common/ConfigManager.cpp src/common/$(IntermediateDirectory)/ConfigManager$(DependSuffix)
	@$(MakeDirCommand) "src/common/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/common/ConfigManager.cpp" $(CmpOptions) $(ObjectSwitch)src/common/$(IntermediateDirectory)/ConfigManager$(ObjectSuffix) $(IncludePath)
src/common/$(IntermediateDirectory)/ConfigManager$(DependSuffix): src/common/ConfigManager.cpp
	@$(MakeDirCommand) "src/common/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/common/$(IntermediateDirectory)/ConfigManager$(ObjectSuffix) -MFsrc/common/$(IntermediateDirectory)/ConfigManager$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/common/ConfigManager.cpp"

src/common/$(IntermediateDirectory)/DBManager$(ObjectSuffix): src/common/DBManager.cpp src/common/$(IntermediateDirectory)/DBManager$(DependSuffix)
	@$(MakeDirCommand) "src/common/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/common/DBManager.cpp" $(CmpOptions) $(ObjectSwitch)src/common/$(IntermediateDirectory)/DBManager$(ObjectSuffix) $(IncludePath)
src/common/$(IntermediateDirectory)/DBManager$(DependSuffix): src/common/DBManager.cpp
	@$(MakeDirCommand) "src/common/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/common/$(IntermediateDirectory)/DBManager$(ObjectSuffix) -MFsrc/common/$(IntermediateDirectory)/DBManager$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/common/DBManager.cpp"

src/common/$(IntermediateDirectory)/FileManager$(ObjectSuffix): src/common/FileManager.cpp src/common/$(IntermediateDirectory)/FileManager$(DependSuffix)
	@$(MakeDirCommand) "src/common/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/common/FileManager.cpp" $(CmpOptions) $(ObjectSwitch)src/common/$(IntermediateDirectory)/FileManager$(ObjectSuffix) $(IncludePath)
src/common/$(IntermediateDirectory)/FileManager$(DependSuffix): src/common/FileManager.cpp
	@$(MakeDirCommand) "src/common/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/common/$(IntermediateDirectory)/FileManager$(ObjectSuffix) -MFsrc/common/$(IntermediateDirectory)/FileManager$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/common/FileManager.cpp"

src/gui/$(IntermediateDirectory)/CBItemData$(ObjectSuffix): src/gui/CBItemData.cpp src/gui/$(IntermediateDirectory)/CBItemData$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/CBItemData.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/CBItemData$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/CBItemData$(DependSuffix): src/gui/CBItemData.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/CBItemData$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/CBItemData$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/CBItemData.cpp"

src/gui/$(IntermediateDirectory)/FFCBMainFrame$(ObjectSuffix): src/gui/FFCBMainFrame.cpp src/gui/$(IntermediateDirectory)/FFCBMainFrame$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBMainFrame.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/FFCBMainFrame$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/FFCBMainFrame$(DependSuffix): src/gui/FFCBMainFrame.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/FFCBMainFrame$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/FFCBMainFrame$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBMainFrame.cpp"

src/gui/$(IntermediateDirectory)/FFCBPreferencesDialog$(ObjectSuffix): src/gui/FFCBPreferencesDialog.cpp src/gui/$(IntermediateDirectory)/FFCBPreferencesDialog$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBPreferencesDialog.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/FFCBPreferencesDialog$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/FFCBPreferencesDialog$(DependSuffix): src/gui/FFCBPreferencesDialog.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/FFCBPreferencesDialog$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/FFCBPreferencesDialog$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBPreferencesDialog.cpp"

src/gui/$(IntermediateDirectory)/FFCBPreviewDialog$(ObjectSuffix): src/gui/FFCBPreviewDialog.cpp src/gui/$(IntermediateDirectory)/FFCBPreviewDialog$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBPreviewDialog.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/FFCBPreviewDialog$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/FFCBPreviewDialog$(DependSuffix): src/gui/FFCBPreviewDialog.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/FFCBPreviewDialog$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/FFCBPreviewDialog$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBPreviewDialog.cpp"

src/gui/$(IntermediateDirectory)/FFCBSingleFilePanel$(ObjectSuffix): src/gui/FFCBSingleFilePanel.cpp src/gui/$(IntermediateDirectory)/FFCBSingleFilePanel$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBSingleFilePanel.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/FFCBSingleFilePanel$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/FFCBSingleFilePanel$(DependSuffix): src/gui/FFCBSingleFilePanel.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/FFCBSingleFilePanel$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/FFCBSingleFilePanel$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBSingleFilePanel.cpp"

src/gui/$(IntermediateDirectory)/FFCBDropTarget$(ObjectSuffix): src/gui/FFCBDropTarget.cpp src/gui/$(IntermediateDirectory)/FFCBDropTarget$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBDropTarget.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/FFCBDropTarget$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/FFCBDropTarget$(DependSuffix): src/gui/FFCBDropTarget.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/FFCBDropTarget$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/FFCBDropTarget$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBDropTarget.cpp"

src/gui/$(IntermediateDirectory)/FFCBTextArchivePanelBase$(ObjectSuffix): src/gui/FFCBTextArchivePanelBase.cpp src/gui/$(IntermediateDirectory)/FFCBTextArchivePanelBase$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBTextArchivePanelBase.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/FFCBTextArchivePanelBase$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/FFCBTextArchivePanelBase$(DependSuffix): src/gui/FFCBTextArchivePanelBase.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/FFCBTextArchivePanelBase$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/FFCBTextArchivePanelBase$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBTextArchivePanelBase.cpp"

src/gui/$(IntermediateDirectory)/FFCBTextArchivePanel$(ObjectSuffix): src/gui/FFCBTextArchivePanel.cpp src/gui/$(IntermediateDirectory)/FFCBTextArchivePanel$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBTextArchivePanel.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/FFCBTextArchivePanel$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/FFCBTextArchivePanel$(DependSuffix): src/gui/FFCBTextArchivePanel.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/FFCBTextArchivePanel$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/FFCBTextArchivePanel$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBTextArchivePanel.cpp"

src/gui/$(IntermediateDirectory)/cbgui$(ObjectSuffix): src/gui/cbgui.cpp src/gui/$(IntermediateDirectory)/cbgui$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/cbgui.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/cbgui$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/cbgui$(DependSuffix): src/gui/cbgui.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/cbgui$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/cbgui$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/cbgui.cpp"

src/gui/$(IntermediateDirectory)/FFCBEEVBFilePanel$(ObjectSuffix): src/gui/FFCBEEVBFilePanel.cpp src/gui/$(IntermediateDirectory)/FFCBEEVBFilePanel$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBEEVBFilePanel.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/FFCBEEVBFilePanel$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/FFCBEEVBFilePanel$(DependSuffix): src/gui/FFCBEEVBFilePanel.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/FFCBEEVBFilePanel$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/FFCBEEVBFilePanel$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBEEVBFilePanel.cpp"

src/gui/$(IntermediateDirectory)/FFCBTextCtrl$(ObjectSuffix): src/gui/FFCBTextCtrl.cpp src/gui/$(IntermediateDirectory)/FFCBTextCtrl$(DependSuffix)
	@$(MakeDirCommand) "src/gui/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBTextCtrl.cpp" $(CmpOptions) $(ObjectSwitch)src/gui/$(IntermediateDirectory)/FFCBTextCtrl$(ObjectSuffix) $(IncludePath)
src/gui/$(IntermediateDirectory)/FFCBTextCtrl$(DependSuffix): src/gui/FFCBTextCtrl.cpp
	@$(MakeDirCommand) "src/gui/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/gui/$(IntermediateDirectory)/FFCBTextCtrl$(ObjectSuffix) -MFsrc/gui/$(IntermediateDirectory)/FFCBTextCtrl$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/gui/FFCBTextCtrl.cpp"

src/$(IntermediateDirectory)/app$(ObjectSuffix): src/app.cpp src/$(IntermediateDirectory)/app$(DependSuffix)
	@$(MakeDirCommand) "src/Release"
	$(CompilerName) $(SourceSwitch) "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/app.cpp" $(CmpOptions) $(ObjectSwitch)src/$(IntermediateDirectory)/app$(ObjectSuffix) $(IncludePath)
src/$(IntermediateDirectory)/app$(DependSuffix): src/app.cpp
	@$(MakeDirCommand) "src/Release"
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MTsrc/$(IntermediateDirectory)/app$(ObjectSuffix) -MFsrc/$(IntermediateDirectory)/app$(DependSuffix) -MM "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/src/app.cpp"

$(IntermediateDirectory)/resource.rc$(ObjectSuffix): resource.rc
	@$(MakeDirCommand) "./Release"
	$(RcCompilerName) -i "D:/Documenti/CodeLite Projects/workspace/FFCBEditor/resource.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/resource.rc$(ObjectSuffix) $(RcIncludePath)

-include src/cblib/$(IntermediateDirectory)/*$(DependSuffix)
-include src/common/$(IntermediateDirectory)/*$(DependSuffix)
-include src/gui/$(IntermediateDirectory)/*$(DependSuffix)
-include src/$(IntermediateDirectory)/*$(DependSuffix)
-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) src/cblib/$(IntermediateDirectory)/CBSingleFile$(ObjectSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBSingleFile$(DependSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBSingleFile$(PreprocessSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBSingleFileTextSection$(ObjectSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBSingleFileTextSection$(DependSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBSingleFileTextSection$(PreprocessSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBTextArchive$(ObjectSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBTextArchive$(DependSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBTextArchive$(PreprocessSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBTextArchiveSection$(ObjectSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBTextArchiveSection$(DependSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBTextArchiveSection$(PreprocessSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBFREBArchive$(ObjectSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBFREBArchive$(DependSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBFREBArchive$(PreprocessSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBEEVBFile$(ObjectSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBEEVBFile$(DependSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBEEVBFile$(PreprocessSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBEEVBTextSection$(ObjectSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBEEVBTextSection$(DependSuffix)
	$(RM) src/cblib/$(IntermediateDirectory)/CBEEVBTextSection$(PreprocessSuffix)
	$(RM) src/common/$(IntermediateDirectory)/ConfigManager$(ObjectSuffix)
	$(RM) src/common/$(IntermediateDirectory)/ConfigManager$(DependSuffix)
	$(RM) src/common/$(IntermediateDirectory)/ConfigManager$(PreprocessSuffix)
	$(RM) src/common/$(IntermediateDirectory)/DBManager$(ObjectSuffix)
	$(RM) src/common/$(IntermediateDirectory)/DBManager$(DependSuffix)
	$(RM) src/common/$(IntermediateDirectory)/DBManager$(PreprocessSuffix)
	$(RM) src/common/$(IntermediateDirectory)/FileManager$(ObjectSuffix)
	$(RM) src/common/$(IntermediateDirectory)/FileManager$(DependSuffix)
	$(RM) src/common/$(IntermediateDirectory)/FileManager$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/CBItemData$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/CBItemData$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/CBItemData$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBMainFrame$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBMainFrame$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBMainFrame$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBPreferencesDialog$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBPreferencesDialog$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBPreferencesDialog$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBPreviewDialog$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBPreviewDialog$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBPreviewDialog$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBSingleFilePanel$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBSingleFilePanel$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBSingleFilePanel$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBDropTarget$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBDropTarget$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBDropTarget$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBTextArchivePanelBase$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBTextArchivePanelBase$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBTextArchivePanelBase$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBTextArchivePanel$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBTextArchivePanel$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBTextArchivePanel$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/cbgui$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/cbgui$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/cbgui$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBEEVBFilePanel$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBEEVBFilePanel$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBEEVBFilePanel$(PreprocessSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBTextCtrl$(ObjectSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBTextCtrl$(DependSuffix)
	$(RM) src/gui/$(IntermediateDirectory)/FFCBTextCtrl$(PreprocessSuffix)
	$(RM) src/$(IntermediateDirectory)/app$(ObjectSuffix)
	$(RM) src/$(IntermediateDirectory)/app$(DependSuffix)
	$(RM) src/$(IntermediateDirectory)/app$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/resource.rc$(ObjectSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe


