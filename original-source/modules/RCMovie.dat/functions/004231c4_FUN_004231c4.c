/*
 * FUN_004231c4 at 004231c4
 * undefined4 * __stdcall FUN_004231c4(void)
 * Address ranges: 004231c4-00423274
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_004231c4(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_0043f814 == DAT_0043f804) {
    pvVar2 = HeapReAlloc(DAT_0043f81c,0,DAT_0043f818,(DAT_0043f804 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_0043f804 = DAT_0043f804 + 0x10;
    DAT_0043f818 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_0043f818 + DAT_0043f814 * 0x14);
  pvVar2 = HeapAlloc(DAT_0043f81c,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_0043f814 = DAT_0043f814 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_0043f81c,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}

