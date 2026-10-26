/*
 * FUN_00402a30 at 00402a30
 * undefined __register FUN_00402a30(byte * param_1, byte * param_2, byte param_3)
 * Address ranges: 00402a30-00402a5e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402a30(byte *param_1,byte *param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 < *param_2) {
    *param_1 = param_3;
    uVar1 = (uint)param_3;
    while( true ) {
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      if (uVar1 == 0) break;
      uVar1 = uVar1 - 1;
      *param_1 = *param_2;
    }
    return;
  }
  uVar1 = *param_2 + 1;
  uVar2 = uVar1 & 3;
  for (uVar1 = uVar1 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(undefined4 *)param_1 = *(undefined4 *)param_2;
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
  }
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

