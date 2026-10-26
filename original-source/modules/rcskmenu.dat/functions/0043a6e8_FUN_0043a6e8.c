/*
 * FUN_0043a6e8 at 0043a6e8
 * uint __register FUN_0043a6e8(int param_1)
 * Address ranges: 0043a6e8-0043a730
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0043a6e8(int param_1)

{
  int *piVar1;
  undefined4 extraout_ECX;
  uint uVar2;
  undefined4 extraout_EDX;
  
  uVar2 = 0;
  if (PTR_DAT_0047c9d8[9] != '\0') {
    if (*(char *)(param_1 + 0x35) == '\0') {
      uVar2 = (uint)(*(char *)(param_1 + 0x24) == '\x01');
    }
    else {
      piVar1 = FUN_00435898((POINT *)(param_1 + 0x48));
      if (piVar1 == (int *)0x0) {
        uVar2 = FUN_00431544(*(int *)PTR_DAT_0047c86c);
      }
      else {
        uVar2 = FUN_00403088(piVar1,extraout_EDX,extraout_ECX);
      }
    }
  }
  return uVar2;
}

