/*
 * FUN_0043286c at 0043286c
 * undefined __register FUN_0043286c(int param_1, char param_2)
 * Address ranges: 0043286c-004328aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043286c(int param_1,char param_2)

{
  int iVar1;
  undefined3 in_register_00000009;
  
  if (param_2 != *(char *)(param_1 + 0x78)) {
    *(char *)(param_1 + 0x78) = param_2;
    if (param_2 == '\0') {
      FUN_00402eac(*(int **)(param_1 + 0x74));
      *(undefined4 *)(param_1 + 0x74) = 0;
    }
    else {
      iVar1 = (**(code **)(PTR_PTR_0047b6b0 + 0x2c))
                        (PTR_PTR_0047b6b0,CONCAT31(in_register_00000009,1),param_1);
      *(int *)(param_1 + 0x74) = iVar1;
      FUN_0043f7d8(iVar1,*(int *)(param_1 + 0x4c));
    }
  }
  return;
}

