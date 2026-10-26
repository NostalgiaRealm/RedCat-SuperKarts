/*
 * FUN_00420db5 at 00420db5
 * undefined4 * __stdcall FUN_00420db5(void)
 * Address ranges: 00420db5-00420e2c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 * FUN_00420db5(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  iVar1 = 0;
  piVar4 = DAT_0043e7e8;
  if (0 < DAT_0043f800) {
    do {
      if (*piVar4 == 0) {
        pvVar2 = _malloc(0x20);
        DAT_0043e7e8[iVar1] = (int)pvVar2;
        puVar3 = (undefined4 *)DAT_0043e7e8[iVar1];
        if (puVar3 == (undefined4 *)0x0) {
          return (undefined4 *)0x0;
        }
LAB_00420e10:
        if (puVar3 == (undefined4 *)0x0) {
          return (undefined4 *)0x0;
        }
        puVar3[4] = 0xffffffff;
        puVar3[1] = 0;
        puVar3[3] = 0;
        puVar3[2] = 0;
        *puVar3 = 0;
        puVar3[7] = 0;
        return puVar3;
      }
      if ((*(byte *)(*piVar4 + 0xc) & 0x83) == 0) {
        puVar3 = (undefined4 *)DAT_0043e7e8[iVar1];
        goto LAB_00420e10;
      }
      iVar1 = iVar1 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar1 < DAT_0043f800);
  }
  return (undefined4 *)0x0;
}

