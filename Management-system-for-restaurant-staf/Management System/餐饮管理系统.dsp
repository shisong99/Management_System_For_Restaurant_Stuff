# Microsoft Developer Studio Project File - Name="餐饮管理系统" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=餐饮管理系统 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "餐饮管理系统.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "餐饮管理系统.mak" CFG="餐饮管理系统 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "餐饮管理系统 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "餐饮管理系统 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "餐饮管理系统 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "餐饮管理系统 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "餐饮管理系统 - Win32 Release"
# Name "餐饮管理系统 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ADOConn.cpp
# End Source File
# Begin Source File

SOURCE=.\BuyGoods.cpp
# End Source File
# Begin Source File

SOURCE=.\cookermenu.cpp
# End Source File
# Begin Source File

SOURCE=.\CopyDatabase.cpp
# End Source File
# Begin Source File

SOURCE=.\DishesInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\DishesNum.cpp
# End Source File
# Begin Source File

SOURCE=.\DishesTotle.cpp
# End Source File
# Begin Source File

SOURCE=.\GoodsInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\GoodsSelect.cpp
# End Source File
# Begin Source File

SOURCE=.\Login.cpp
# End Source File
# Begin Source File

SOURCE=.\ManagePower.cpp
# End Source File
# Begin Source File

SOURCE=.\member.cpp
# End Source File
# Begin Source File

SOURCE=.\MonthIncome.cpp
# End Source File
# Begin Source File

SOURCE=.\OpenTable.cpp
# End Source File
# Begin Source File

SOURCE=.\PayOrder.cpp
# End Source File
# Begin Source File

SOURCE=.\Register.cpp
# End Source File
# Begin Source File

SOURCE=.\ReturnDatabase.cpp
# End Source File
# Begin Source File

SOURCE=.\SelectDishes.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\UpdateDishes.cpp
# End Source File
# Begin Source File

SOURCE=.\UserManage.cpp
# End Source File
# Begin Source File

SOURCE=".\餐饮管理系统.cpp"
# End Source File
# Begin Source File

SOURCE=".\餐饮管理系统Dlg.cpp"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ADOConn.h
# End Source File
# Begin Source File

SOURCE=.\AppFace.h
# End Source File
# Begin Source File

SOURCE=.\BuyGoods.h
# End Source File
# Begin Source File

SOURCE=.\cookermenu.h
# End Source File
# Begin Source File

SOURCE=.\CopyDatabase.h
# End Source File
# Begin Source File

SOURCE=.\DishesInfo.h
# End Source File
# Begin Source File

SOURCE=.\DishesNum.h
# End Source File
# Begin Source File

SOURCE=.\DishesTotle.h
# End Source File
# Begin Source File

SOURCE=.\GoodsInfo.h
# End Source File
# Begin Source File

SOURCE=.\GoodsSelect.h
# End Source File
# Begin Source File

SOURCE=.\Login.h
# End Source File
# Begin Source File

SOURCE=.\ManagePower.h
# End Source File
# Begin Source File

SOURCE=.\member.h
# End Source File
# Begin Source File

SOURCE=.\MonthIncome.h
# End Source File
# Begin Source File

SOURCE=.\OpenTable.h
# End Source File
# Begin Source File

SOURCE=.\PayOrder.h
# End Source File
# Begin Source File

SOURCE=.\Register.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ReturnDatabase.h
# End Source File
# Begin Source File

SOURCE=.\SelectDishes.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\UpdateDishes.h
# End Source File
# Begin Source File

SOURCE=.\UserManage.h
# End Source File
# Begin Source File

SOURCE=".\餐饮管理系统.h"
# End Source File
# Begin Source File

SOURCE=".\餐饮管理系统.rc"
# End Source File
# Begin Source File

SOURCE=".\餐饮管理系统Dlg.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\142.ico
# End Source File
# Begin Source File

SOURCE=.\res\167.ico
# End Source File
# Begin Source File

SOURCE=.\res\2.ico
# End Source File
# Begin Source File

SOURCE=.\res\33.ico
# End Source File
# Begin Source File

SOURCE=.\res\42.ico
# End Source File
# Begin Source File

SOURCE=.\res\57.ico
# End Source File
# Begin Source File

SOURCE=.\res\61.ico
# End Source File
# Begin Source File

SOURCE=.\res\66.ico
# End Source File
# Begin Source File

SOURCE=.\res\71.ico
# End Source File
# Begin Source File

SOURCE=.\res\82.ico
# End Source File
# Begin Source File

SOURCE=.\res\91.ico
# End Source File
# Begin Source File

SOURCE=.\res\anniu.bmp
# End Source File
# Begin Source File

SOURCE=.\res\anniubeijing.bmp
# End Source File
# Begin Source File

SOURCE=.\res\background.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buygoods_ensure1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buygoods_ensure2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buygoods_exit1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buygoods_exit2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buygoods_left1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buygoods_left2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buygoods_reset1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buygoods_reset2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buygoods_right1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\buygoods_right2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cancelanniu.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cemian.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cookermenu_clear1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cookermenu_clear2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cookermenu_delete1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cookermenu_delete2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cookermenu_fresh1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cookermenu_fresh2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\da.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dada.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dadada.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dishinfo_add1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dishinfo_add2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dishinfo_back1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dishinfo_back2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dishinfo_delete1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dishinfo_delete2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dishinfo_update1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dishinfo_update2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dishnum_back1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dishnum_back2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dishnum_puton1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dishnum_puton2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\diwen.bmp
# End Source File
# Begin Source File

SOURCE=.\res\duihuakuangbeijing.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FirstBackground.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FirstBackground1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\goodsselect_cancel1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\goodsselect_cancel2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\goodsselect_query1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\goodsselect_query2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\idr_main.ico
# End Source File
# Begin Source File

SOURCE=.\res\kuangbeijing.bmp
# End Source File
# Begin Source File

SOURCE=".\res\login#.ico"
# End Source File
# Begin Source File

SOURCE=.\res\login.bmp
# End Source File
# Begin Source File

SOURCE=.\res\login_cancel1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\login_cancel2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\login_login1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\login_login2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mangepower_set1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mangepower_set2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\monthincome_cancel1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\monthincome_cancel2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\monthincome_enquery1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\monthincome_enquery2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\my_change1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\my_change2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\my_count1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\my_count2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\my_eat1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\my_eat2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\my_employ1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\my_employ2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\my_exit1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\my_exit2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\my_login1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\my_login2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\OKanniu.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ot_back1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ot_back2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ot_select1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ot_select2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\pay_member1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\pay_member2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\pay_OK1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\pay_OK2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\register_cancel1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\register_cancel2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\register_register1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\register_register2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rs_browse1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rs_browse2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rs_cancel1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rs_cancel2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rs_r1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rs_r2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sd_cancel1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sd_cancel2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sd_cancelb1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sd_cancelb2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sd_count1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sd_count2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sd_OK1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sd_OK2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sd_pay1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sd_pay2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sd_select1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sd_select2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\useramanage_cancel2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\usermanage_cancel1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\usermanage_delete1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\usermanage_delete2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\usermanage_update1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\usermanage_update2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\xiangchisha.bmp
# End Source File
# Begin Source File

SOURCE=".\res\餐饮管理系统.ico"
# End Source File
# Begin Source File

SOURCE=".\res\餐饮管理系统.rc2"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
