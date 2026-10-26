/*
 * FUN_00430608 at 00430608
 * undefined4 __register FUN_00430608(int param_1, int param_2)
 * Address ranges: 00430608-0043062d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00430608(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = 0;
  if (param_2 != -1) {
    for (puVar2 = *(undefined4 **)(param_1 + 0x50);
        (puVar2 != (undefined4 *)0x0 && (param_2 != puVar2[1])); puVar2 = (undefined4 *)*puVar2) {
    }
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(param_1 + 0x54);
    }
    else {
      uVar1 = puVar2[2];
    }
  }
  return uVar1;
}

