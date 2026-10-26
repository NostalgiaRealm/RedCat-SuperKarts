/*
 * FUN_00457d10 at 00457d10
 * undefined FUN_00457d10(void)
 * Address ranges: 00457d10-00457d43
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00457d10(undefined4 *param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 0x28) == '\0') &&
     (iVar1 = 0, DAT_00508610 != -1 && -1 < DAT_00508610 + 1)) {
    do {
      *param_1 = 0xfffffc18;
      *(undefined1 *)(param_1 + 3) = 0;
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 4;
    } while (iVar1 < DAT_00508610 + 1);
  }
  return;
}

