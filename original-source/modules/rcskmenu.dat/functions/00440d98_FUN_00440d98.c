/*
 * FUN_00440d98 at 00440d98
 * undefined FUN_00440d98(void)
 * Address ranges: 00440d98-00440dd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440d98(int *param_1)

{
  bool bVar1;
  
  (**(code **)(*param_1 + -0x10))();
  bVar1 = FUN_0043f858(param_1);
  if (bVar1) {
    FUN_0043f868(param_1,'\0');
    if ((*(byte *)(param_1 + 0x11) & 1) != 0) {
      FUN_004405f0((int)param_1,0x202,0,0xffffffff);
      return;
    }
  }
  else {
    *(ushort *)(param_1 + 0x11) = *(ushort *)(param_1 + 0x11) & 0xfffe;
  }
  return;
}

