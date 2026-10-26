/*
 * FUN_0049f840 at 0049f840
 * undefined FUN_0049f840(void)
 * Address ranges: 0049f840-0049f8c4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0049f840(void)

{
  int iVar1;
  
  if (DAT_006a5c44 == 1) {
    FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,&DAT_006a5c65,&DAT_006a5c4c,
                 DAT_006a5c3c);
    if (DAT_006a5c38 != 0) {
      iVar1 = DAT_006a5c38 + -4;
      FUN_004be99e(DAT_006a5c38,0xa9,*(undefined4 *)(DAT_006a5c38 + -4),FUN_004aa0b0);
      FUN_004bc150(iVar1);
    }
  }
  if (DAT_006a5c44 != 0) {
    FUN_004bc150(DAT_006a5c48);
    DAT_006a5c44 = 0;
  }
  FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  FUN_004ad430();
  return;
}

