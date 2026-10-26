/*
 * FUN_004a1100 at 004a1100
 * undefined FUN_004a1100(void)
 * Address ranges: 004a1100-004a125f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004a1100(int *param_1,uint param_2)

{
  uint *puVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_004d172b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (param_1[3] != 0) {
    ExceptionList = &pvStack_c;
    if (param_1[3] == 1) {
      ExceptionList = &pvStack_c;
      FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,(int)param_1 + 0x2d,param_1 + 5,
                   param_1[1]);
      iVar3 = *param_1;
      if (iVar3 != 0) {
        FUN_004be99e(iVar3,0xa9,*(undefined4 *)(iVar3 + -4),FUN_004aa0b0);
        FUN_004bc150(iVar3 + -4);
      }
    }
    if (param_1[3] != 0) {
      FUN_004bc150(param_1[4]);
      param_1[3] = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  if ((int)param_2 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,s___array_hpp_004fc894,0x107,
                 (int)param_1 + 0x2d,param_1 + 5,param_2);
  }
  puVar1 = operator_new(param_2 * 0xa9 + 4);
  uStack_4 = 0;
  if (puVar1 == (uint *)0x0) {
    puVar5 = (uint *)0x0;
  }
  else {
    puVar5 = puVar1 + 1;
    *puVar1 = param_2;
    FUN_004be91c(puVar5,0xa9,param_2,FUN_004a08a0,FUN_004aa0b0);
  }
  uStack_4 = 0xffffffff;
  *param_1 = (int)puVar5;
  param_1[1] = param_2;
  param_1[2] = 0;
  pvVar2 = operator_new(param_2);
  param_1[4] = (int)pvVar2;
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,(int)param_1 + 0x2d,param_1 + 5,
               param_1[1]);
  param_1[3] = 1;
  iVar3 = 0;
  if (0 < (int)param_2) {
    do {
      iVar4 = iVar3 + 1;
      *(undefined1 *)(iVar3 + param_1[4]) = 0;
      iVar3 = iVar4;
    } while (iVar4 < (int)param_2);
  }
  ExceptionList = pvStack_c;
  return;
}

