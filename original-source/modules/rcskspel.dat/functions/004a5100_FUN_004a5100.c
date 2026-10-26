/*
 * FUN_004a5100 at 004a5100
 * undefined FUN_004a5100(void)
 * Address ranges: 004a5100-004a5401
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_004a5100(undefined4 *param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  FUN_004afce0(s_init_animsys__meshes__d__texture_004fcd98,param_2,param_3,param_4,param_5);
  if (param_1[9] != 0) {
    if (param_1[9] == 1) {
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,(int)param_1 + 0x45,param_1 + 0xb,
                   param_1[7]);
      FUN_004bc150(param_1[6]);
    }
    if (param_1[9] != 0) {
      FUN_004bc150(param_1[10]);
      param_1[9] = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  if ((int)param_2 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,s___array_hpp_004fc894,0x107,
                 (int)param_1 + 0x45,param_1 + 0xb,param_2);
  }
  pvVar1 = operator_new(param_2 * 0x15);
  param_1[6] = pvVar1;
  param_1[7] = param_2;
  param_1[8] = 0;
  pvVar1 = operator_new(param_2);
  param_1[10] = pvVar1;
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,(int)param_1 + 0x45,param_1 + 0xb,
               param_1[7]);
  iVar2 = 0;
  param_1[9] = 1;
  if (0 < (int)param_2) {
    do {
      iVar2 = iVar2 + 1;
      *(undefined1 *)(param_1[10] + -1 + iVar2) = 0;
    } while (iVar2 < (int)param_2);
  }
  if (*(int *)((int)param_1 + 0x6a) != 0) {
    FUN_00405f70();
  }
  if ((int)param_3 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,s___array_hpp_004fc894,0x107,
                 (int)param_1 + 0x8b,(int)param_1 + 0x72,param_3);
  }
  pvVar1 = operator_new(param_3 * 0x15);
  *(void **)((int)param_1 + 0x5e) = pvVar1;
  *(uint *)((int)param_1 + 0x62) = param_3;
  *(undefined4 *)((int)param_1 + 0x66) = 0;
  pvVar1 = operator_new(param_3);
  *(void **)((int)param_1 + 0x6e) = pvVar1;
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,(int)param_1 + 0x8b,(int)param_1 + 0x72,
               *(undefined4 *)((int)param_1 + 0x62));
  iVar2 = 0;
  *(undefined4 *)((int)param_1 + 0x6a) = 1;
  if (0 < (int)param_3) {
    do {
      iVar2 = iVar2 + 1;
      *(undefined1 *)(*(int *)((int)param_1 + 0x6e) + -1 + iVar2) = 0;
    } while (iVar2 < (int)param_3);
  }
  if (DAT_006a5f3c != 0) {
    FUN_00405f70();
  }
  if ((int)param_4 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,s___array_hpp_004fc894,0x107,
                 &DAT_006a5f5d,&DAT_006a5f44,param_4);
  }
  DAT_006a5f30 = operator_new(param_4 << 4);
  DAT_006a5f34 = param_4;
  DAT_006a5f38 = 0;
  DAT_006a5f40 = operator_new(param_4);
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,&DAT_006a5f5d,&DAT_006a5f44,DAT_006a5f34)
  ;
  DAT_006a5f3c = 1;
  iVar2 = 0;
  if (0 < (int)param_4) {
    do {
      iVar3 = iVar2 + 1;
      *(undefined1 *)((int)DAT_006a5f40 + iVar2) = 0;
      iVar2 = iVar3;
    } while (iVar3 < (int)param_4);
  }
  if (DAT_006a5f84 != 0) {
    FUN_00405f70();
  }
  if ((int)param_5 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,s___array_hpp_004fc894,0x107,
                 &DAT_006a5fa5,&DAT_006a5f8c,param_5);
  }
  DAT_006a5f78 = operator_new(param_5 * 9);
  DAT_006a5f7c = param_5;
  DAT_006a5f80 = 0;
  DAT_006a5f88 = operator_new(param_5);
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,&DAT_006a5fa5,&DAT_006a5f8c,DAT_006a5f7c)
  ;
  DAT_006a5f84 = 1;
  iVar2 = 0;
  if (0 < (int)param_5) {
    do {
      iVar3 = iVar2 + 1;
      *(undefined1 *)((int)DAT_006a5f88 + iVar2) = 0;
      iVar2 = iVar3;
    } while (iVar3 < (int)param_5);
  }
  FUN_004a7110(param_5);
  param_1[2] = param_4;
  param_1[1] = param_5;
  param_1[3] = param_3;
  param_1[4] = param_2;
  *param_1 = 1;
  return;
}

