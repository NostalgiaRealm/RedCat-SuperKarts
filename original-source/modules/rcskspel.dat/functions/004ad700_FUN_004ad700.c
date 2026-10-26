/*
 * FUN_004ad700 at 004ad700
 * undefined FUN_004ad700(void)
 * Address ranges: 004ad700-004ad85e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __fastcall FUN_004ad700(int *param_1)

{
  int *_Dest;
  char *_Dest_00;
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d190b;
  local_c = ExceptionList;
  _Dest = param_1 + 5;
  ExceptionList = &local_c;
  param_1[3] = 0;
  _strncpy((char *)_Dest,s_m_txf_drv_info_004fe158,0x19);
  _Dest_00 = (char *)((int)param_1 + 0x2d);
  _strncpy(_Dest_00,s_c_txf_drv_info_004fe148,0x19);
  if (param_1[3] != 0) {
    if (param_1[3] == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,_Dest_00,_Dest,param_1[1]);
      iVar4 = *param_1;
      if (iVar4 != 0) {
        FUN_004be99e(iVar4,0xb0,*(undefined4 *)(iVar4 + -4),FUN_004ad6a0);
        FUN_004bc150(iVar4 + -4);
      }
    }
    if (param_1[3] != 0) {
      FUN_004bc150(param_1[4]);
      param_1[3] = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  puVar1 = operator_new(0x44c4);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = puVar1 + 1;
    *puVar1 = 100;
    FUN_004be91c(puVar2,0xb0,100,FUN_004ad6b0,FUN_004ad6a0);
  }
  local_4 = 0xffffffff;
  *param_1 = (int)puVar2;
  param_1[1] = 100;
  param_1[2] = 0;
  pvVar3 = operator_new(100);
  param_1[4] = (int)pvVar3;
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,_Dest_00,_Dest,param_1[1]);
  param_1[3] = 1;
  iVar4 = 0;
  do {
    iVar5 = iVar4 + 1;
    *(undefined1 *)(iVar4 + param_1[4]) = 0;
    iVar4 = iVar5;
  } while (iVar5 < 100);
  *(undefined4 *)((int)param_1 + 0x46) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x4a) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x4e) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x52) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x5a) = 0;
  *(undefined4 *)((int)param_1 + 0x5e) = 0;
  ExceptionList = local_c;
  return param_1;
}

