/*
 * FUN_00413270 at 00413270
 * undefined4 __cdecl FUN_00413270(int param_1)
 * Address ranges: 00413270-00413354
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00413270(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  for (local_c = 0;
      (*(int *)(param_1 + 4 + local_c * 0xc) != -1 && (*(int *)(param_1 + local_c * 0xc) != -1));
      local_c = local_c + 1) {
  }
  DAT_00434c1c = local_c;
  iVar1 = FUN_00413355(local_c);
  if (iVar1 == 0) {
    for (local_c = 0; local_c < DAT_00434c1c; local_c = local_c + 1) {
      *(undefined4 *)(DAT_0043d858 + local_c * 0xc) = *(undefined4 *)(param_1 + local_c * 0xc);
      *(undefined4 *)(DAT_0043d858 + 4 + local_c * 0xc) =
           *(undefined4 *)(param_1 + 4 + local_c * 0xc);
      *(undefined4 *)(DAT_0043d858 + 8 + local_c * 0xc) =
           *(undefined4 *)(param_1 + 8 + local_c * 0xc);
    }
    _DAT_0043d85c = 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 2000;
  }
  return uVar2;
}

