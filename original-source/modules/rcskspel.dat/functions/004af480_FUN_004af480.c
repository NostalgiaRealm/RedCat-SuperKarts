/*
 * FUN_004af480 at 004af480
 * undefined FUN_004af480(void)
 * Address ranges: 004af480-004af67d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __thiscall FUN_004af480(int *param_1,uint param_2)

{
  int *_Dest;
  char *_Dest_00;
  uint *puVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  void *unaff_EBX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d1973;
  pvStack_c = ExceptionList;
  _Dest = param_1 + 5;
  ExceptionList = &pvStack_c;
  param_1[3] = 0;
  _strncpy((char *)_Dest,s_m_d3d_drv_info_004fe7c0,0x19);
  _Dest_00 = (char *)((int)param_1 + 0x2d);
  _strncpy(_Dest_00,s_c_d3d_drv_info_004fe7b0,0x19);
  if (param_1[3] != 0) {
    if (param_1[3] == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,_Dest_00,_Dest,param_1[1]);
      iVar4 = *param_1;
      if (iVar4 != 0) {
        FUN_004be99e(iVar4,0x1d8,*(undefined4 *)(iVar4 + -4),FUN_004af070);
        FUN_004bc150((undefined4 *)(iVar4 + -4));
      }
    }
    if (param_1[3] != 0) {
      FUN_004bc150(param_1[4]);
      param_1[3] = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  FUN_004afce0(s_T_ARRAY___init___16_16s___16_16s_004de6c8,_Dest_00,_Dest,0);
  param_1[4] = 0;
  param_1[3] = 0;
  local_4 = 0;
  if ((int)param_2 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,s___array_hpp_004fc894,0x107,_Dest_00,
                 _Dest,param_2);
  }
  puVar1 = operator_new(param_2 * 0x1d8 + 4);
  local_4._0_1_ = 1;
  if (puVar1 == (uint *)0x0) {
    puVar1 = (uint *)0x0;
  }
  else {
    *puVar1 = param_2;
    puVar1 = puVar1 + 1;
    FUN_004be91c(puVar1,0x1d8,param_2,FUN_004af000,FUN_004af070);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  *param_1 = (int)puVar1;
  param_1[1] = param_2;
  param_1[2] = 0;
  pvVar2 = operator_new(param_2);
  param_1[4] = (int)pvVar2;
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,_Dest_00,_Dest,param_1[1]);
  param_1[3] = 1;
  iVar4 = 0;
  if (0 < (int)param_2) {
    do {
      iVar3 = iVar4 + 1;
      *(undefined1 *)(iVar4 + param_1[4]) = 0;
      iVar4 = iVar3;
    } while (iVar3 < (int)param_2);
  }
  *(undefined4 *)((int)param_1 + 0x46) = 0;
  *(undefined4 *)((int)param_1 + 0x4a) = 0;
  FUN_004afce0(s_______Enumerating_Devices_START___004fe840);
  iVar4 = (**(code **)(*DAT_006a62dc + 0xc))(DAT_006a62dc,FUN_004af0d0,param_1);
  if (iVar4 != 0) {
    uVar5 = FUN_004aaa00(iVar4);
    FUN_004afee0(s__s__d____D3DError_EnumDevice_____004fe190,
                 s_D__work_libs_DX3D_D3dinfo_cpp_004fe790,0x60,uVar5);
  }
  FUN_004afce0(s_______Enumerating_Devices_EINDE___004fe818);
  ExceptionList = unaff_EBX;
  return param_1;
}

