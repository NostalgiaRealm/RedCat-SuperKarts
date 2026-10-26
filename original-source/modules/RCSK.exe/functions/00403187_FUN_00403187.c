/*
 * FUN_00403187 at 00403187
 * undefined4 * __stdcall FUN_00403187(void)
 * Address ranges: 00403187-00403237
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_00403187(void)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  
  if (DAT_0040a014 == DAT_0040a004) {
    pvVar2 = HeapReAlloc(DAT_0040a01c,0,DAT_0040a018,(DAT_0040a004 * 5 + 0x50) * 4);
    if (pvVar2 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_0040a004 = DAT_0040a004 + 0x10;
    DAT_0040a018 = pvVar2;
  }
  puVar1 = (undefined4 *)((int)DAT_0040a018 + DAT_0040a014 * 0x14);
  pvVar2 = HeapAlloc(DAT_0040a01c,8,0x41c4);
  puVar1[4] = pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    pvVar2 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar1[3] = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      puVar1[2] = 0xffffffff;
      *puVar1 = 0;
      puVar1[1] = 0;
      DAT_0040a014 = DAT_0040a014 + 1;
      *(undefined4 *)puVar1[4] = 0xffffffff;
      return puVar1;
    }
    HeapFree(DAT_0040a01c,0,(LPVOID)puVar1[4]);
  }
  return (undefined4 *)0x0;
}

