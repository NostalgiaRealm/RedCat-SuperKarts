/*
 * FUN_004288b0 at 004288b0
 * undefined FUN_004288b0(void)
 * Address ranges: 004288b0-00428905
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004288b0(void)

{
  int iVar1;
  
  FUN_004afce0(s_Entry_init_clouds_004e7acc);
  if (DAT_0053b9f0 != 0) {
    iVar1 = FUN_00428880();
    if (iVar1 == 0) {
      FUN_004afce0(s_Clouds_disabled__Hardware_doesn__004e7ae0);
      DAT_0053ba24 = 0;
      return;
    }
  }
  FUN_00428720();
  FUN_00428800();
  DAT_0053a228 = FUN_004a6060(s_S_SFX_PCX_004e7b1c);
  return;
}

