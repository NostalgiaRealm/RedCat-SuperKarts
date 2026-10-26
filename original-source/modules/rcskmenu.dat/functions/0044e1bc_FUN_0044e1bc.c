/*
 * FUN_0044e1bc at 0044e1bc
 * undefined FUN_0044e1bc(void)
 * Address ranges: 0044e1bc-0044e266
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044e1bc(int *param_1,char param_2)

{
  int *piVar1;
  byte extraout_DL;
  undefined4 *in_FS_OFFSET;
  char *pcStack_130;
  undefined4 uStack_120;
  undefined1 *puStack_11c;
  undefined1 *puStack_118;
  byte abStack_10c [256];
  int iStack_c;
  int iStack_8;
  
  iStack_8 = 0;
  iStack_c = 0;
  puStack_118 = (undefined1 *)0x44e1d4;
  piVar1 = FUN_0040320c(param_1,param_2);
  puStack_11c = &LAB_0044e267;
  uStack_120 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_120;
  puStack_118 = &stack0xfffffffc;
  if ((char)piVar1[1] == '\0') {
    puStack_118 = &stack0xfffffffc;
    FUN_00402df8(*piVar1,abStack_10c);
    FUN_00403d74(&iStack_c,abStack_10c);
    pcStack_130 = ": Use class procedure Finalize instead of Destroy";
    FUN_00403e90(&iStack_8,4);
    FUN_00403b34(iStack_8);
  }
  FUN_0040bfec(piVar1 + 2);
  FUN_0044dc14(piVar1,extraout_DL & 0xfc);
  *in_FS_OFFSET = pcStack_130;
  FUN_00403b74(&iStack_c,2);
  return;
}

