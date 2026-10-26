/*
 * FUN_00437cc0 at 00437cc0
 * undefined FUN_00437cc0(void)
 * Address ranges: 00437cc0-00437d07
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool __thiscall FUN_00437cc0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (-1 < param_2) {
    iVar1 = (*(code *)**(undefined4 **)(param_1 + 4))();
    if (param_2 <= iVar1) {
      puVar2 = (undefined4 *)FUN_00436720();
      iVar1 = (**(code **)*puVar2)();
      return 0 < iVar1;
    }
  }
  return false;
}

