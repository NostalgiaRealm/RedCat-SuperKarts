/*
 * FUN_004315a0 at 004315a0
 * undefined FUN_004315a0(void)
 * Address ranges: 004315a0-0043160a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004315a0(undefined4 param_1)

{
  int iVar1;
  undefined1 local_100 [255];
  undefined1 local_1;
  
  if (DAT_0053ba6c != 0) {
    iVar1 = FUN_004bf445(s_beta_log_004eb21c,&DAT_004eb218);
    if (iVar1 != 0) {
      local_1 = 0;
      FUN_004bf8e0(local_100,0xff,param_1,&stack0x00000008);
      FUN_004bf8ae(iVar1,local_100);
      FUN_004bf2c5(iVar1);
    }
  }
  return;
}

