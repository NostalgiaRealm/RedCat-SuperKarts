/*
 * FUN_00494760 at 00494760
 * undefined FUN_00494760(void)
 * Address ranges: 00494760-004948b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00494760(uint param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (DAT_00680b34 != 0) {
    if ((DAT_00680b34 == 1) &&
       (FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_00680b55,&DAT_00680b3c,
                     DAT_00680b2c), DAT_00680b28 != (uint *)0x0)) {
      FUN_004bc150((int)DAT_00680b28 + -4);
    }
    if (DAT_00680b34 != 0) {
      FUN_004bc150(DAT_00680b38);
      DAT_00680b34 = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  if ((int)param_1 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0x107,&DAT_00680b55,&DAT_00680b3c,
                 param_1);
  }
  puVar1 = operator_new(param_1 * 0x984 + 4);
  if (puVar1 == (uint *)0x0) {
    DAT_00680b28 = (uint *)0x0;
    puVar1 = DAT_00680b28;
  }
  else {
    *puVar1 = param_1;
    uVar4 = param_1;
    puVar1 = puVar1 + 1;
    if (-1 < (int)(param_1 - 1)) {
      do {
        FUN_004949a0();
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
  }
  DAT_00680b28 = puVar1;
  DAT_00680b2c = param_1;
  DAT_00680b30 = 0;
  DAT_00680b38 = operator_new(param_1);
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,&DAT_00680b55,&DAT_00680b3c,DAT_00680b2c)
  ;
  DAT_00680b34 = 1;
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      iVar3 = iVar2 + 1;
      *(undefined1 *)((int)DAT_00680b38 + iVar2) = 0;
      iVar2 = iVar3;
    } while (iVar3 < (int)param_1);
  }
  FUN_0049ca60(0x98);
  return;
}

