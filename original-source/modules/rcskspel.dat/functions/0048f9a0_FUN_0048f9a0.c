/*
 * FUN_0048f9a0 at 0048f9a0
 * undefined FUN_0048f9a0(void)
 * Address ranges: 0048f9a0-0048fae1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0048f9a0(uint param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (DAT_0067ee2c != 0) {
    if ((DAT_0067ee2c == 1) &&
       (FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_0067ee4d,&DAT_0067ee34,
                     DAT_0067ee24), DAT_0067ee20 != (uint *)0x0)) {
      FUN_004bc150((int)DAT_0067ee20 + -4);
    }
    if (DAT_0067ee2c != 0) {
      FUN_004bc150(DAT_0067ee30);
      DAT_0067ee2c = 0;
    }
    FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  }
  if ((int)param_1 < 0) {
    FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,
                 s_______Libs_Win3DLib_Include_arra_004fa4c0,0x107,&DAT_0067ee4d,&DAT_0067ee34,
                 param_1);
  }
  puVar1 = operator_new(param_1 * 0xd0 + 4);
  if (puVar1 == (uint *)0x0) {
    DAT_0067ee20 = (uint *)0x0;
    puVar1 = DAT_0067ee20;
  }
  else {
    *puVar1 = param_1;
    uVar4 = param_1;
    puVar1 = puVar1 + 1;
    if (-1 < (int)(param_1 - 1)) {
      do {
        FUN_0048fef0();
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
  }
  DAT_0067ee20 = puVar1;
  DAT_0067ee24 = param_1;
  DAT_0067ee28 = 0;
  DAT_0067ee30 = operator_new(param_1);
  FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,&DAT_0067ee4d,&DAT_0067ee34,DAT_0067ee24)
  ;
  DAT_0067ee2c = 1;
  iVar2 = 0;
  if (0 < (int)param_1) {
    do {
      iVar3 = iVar2 + 1;
      *(undefined1 *)((int)DAT_0067ee30 + iVar2) = 0;
      iVar2 = iVar3;
    } while (iVar3 < (int)param_1);
  }
  return;
}

