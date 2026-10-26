/*
 * FUN_00456fdc at 00456fdc
 * undefined __register FUN_00456fdc(void)
 * Address ranges: 00456fdc-0045701d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00456fdc(void)

{
  int iVar1;
  HMODULE hLibModule;
  int iVar2;
  
  if (DAT_0047e154 != (int *)0x0) {
    iVar1 = (**(code **)(*DAT_0047e154 + 0x14))();
    if (-1 < iVar1 + -1) {
      iVar2 = 0;
      do {
        hLibModule = (HMODULE)(**(code **)(*DAT_0047e154 + 0x18))(DAT_0047e154,iVar2);
        FreeLibrary(hLibModule);
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    FUN_00402eac(DAT_0047e154);
  }
  return;
}

