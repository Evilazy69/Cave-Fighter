##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=DungeonCrawler
ConfigurationName      :=Release
WorkspaceConfiguration :=Release
WorkspacePath          :=/home/evilmint/Documents/Dev/cpp-learning/workspaces/MyWorkspace1
ProjectPath            :=/home/evilmint/Documents/Dev/cpp-learning/workspaces/MyWorkspace1/DungeonCrawler
IntermediateDirectory  :=../$(ProjectName)/build-Release/obj
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Evilmint
Date                   :=23/05/26
CodeLitePath           :=/home/evilmint/.codelite
MakeDirCommand         :=mkdir -p
LinkerName             :=/usr/bin/g++-13
SharedObjectLinkerName :=/usr/bin/g++-13 -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=/home/evilmint/Documents/Dev/cpp-learning/workspaces/MyWorkspace1/$(ProjectName)/build-Release/bin
OutputFile             :=../$(ProjectName)/build-Release/bin/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-13
CC       := /usr/bin/gcc-13
CXXFLAGS :=  -O2 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/inventory.cpp$(ObjectSuffix) $(IntermediateDirectory)/shopArea.cpp$(ObjectSuffix) $(IntermediateDirectory)/stats.cpp$(ObjectSuffix) $(IntermediateDirectory)/caveArea.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/evilmint/Documents/Dev/cpp-learning/workspaces/MyWorkspace1/DungeonCrawler/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/inventory.cpp$(ObjectSuffix): inventory.cpp $(IntermediateDirectory)/inventory.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/evilmint/Documents/Dev/cpp-learning/workspaces/MyWorkspace1/DungeonCrawler/inventory.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/inventory.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/inventory.cpp$(DependSuffix): inventory.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/inventory.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/inventory.cpp$(DependSuffix) -MM inventory.cpp

$(IntermediateDirectory)/inventory.cpp$(PreprocessSuffix): inventory.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/inventory.cpp$(PreprocessSuffix) inventory.cpp

$(IntermediateDirectory)/shopArea.cpp$(ObjectSuffix): shopArea.cpp $(IntermediateDirectory)/shopArea.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/evilmint/Documents/Dev/cpp-learning/workspaces/MyWorkspace1/DungeonCrawler/shopArea.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/shopArea.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/shopArea.cpp$(DependSuffix): shopArea.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/shopArea.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/shopArea.cpp$(DependSuffix) -MM shopArea.cpp

$(IntermediateDirectory)/shopArea.cpp$(PreprocessSuffix): shopArea.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/shopArea.cpp$(PreprocessSuffix) shopArea.cpp

$(IntermediateDirectory)/stats.cpp$(ObjectSuffix): stats.cpp $(IntermediateDirectory)/stats.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/evilmint/Documents/Dev/cpp-learning/workspaces/MyWorkspace1/DungeonCrawler/stats.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stats.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stats.cpp$(DependSuffix): stats.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stats.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/stats.cpp$(DependSuffix) -MM stats.cpp

$(IntermediateDirectory)/stats.cpp$(PreprocessSuffix): stats.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stats.cpp$(PreprocessSuffix) stats.cpp

$(IntermediateDirectory)/caveArea.cpp$(ObjectSuffix): caveArea.cpp $(IntermediateDirectory)/caveArea.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/evilmint/Documents/Dev/cpp-learning/workspaces/MyWorkspace1/DungeonCrawler/caveArea.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/caveArea.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/caveArea.cpp$(DependSuffix): caveArea.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/caveArea.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/caveArea.cpp$(DependSuffix) -MM caveArea.cpp

$(IntermediateDirectory)/caveArea.cpp$(PreprocessSuffix): caveArea.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/caveArea.cpp$(PreprocessSuffix) caveArea.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


