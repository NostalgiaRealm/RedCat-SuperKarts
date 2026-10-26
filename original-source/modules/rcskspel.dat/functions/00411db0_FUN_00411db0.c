/*
 * FUN_00411db0 at 00411db0
 * undefined FUN_00411db0(void)
 * Address ranges: 00411db0-00411e48
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00411db0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  float fStack00000008;
  
  iVar2 = FUN_0040c900();
  fStack00000008 = (float)iVar2 * 10.0 + 100.0;
  cVar1 = FUN_00417e90(param_1);
  if (cVar1 != '\0') {
    fStack00000008 = fStack00000008 + fStack00000008;
  }
  iVar2 = 0;
  do {
    iVar3 = FUN_004906b0(iVar2);
    if (iVar3 == -1) {
      FUN_004afee0(s_No_sub_object__004dffc0);
    }
    iVar2 = iVar2 + 1;
    *(float *)(DAT_006a5c38 + iVar3 * 0xa9 + 0x60) = fStack00000008;
  } while (iVar2 < 4);
  return;
}

