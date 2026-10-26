/*
 * FUN_004029e4 at 004029e4
 * undefined __register FUN_004029e4(byte * param_1, byte * param_2, byte param_3)
 * Address ranges: 004029e4-00402a12
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004029e4(byte *param_1,byte *param_2,byte param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  
  bVar3 = *param_2;
  bVar2 = *param_1 + bVar3;
  if (((!CARRY1(*param_1,bVar3)) && (bVar2 <= param_3)) ||
     (bVar3 = param_3 - *param_1, bVar2 = param_3, *param_1 <= param_3 && bVar3 != 0)) {
    bVar1 = *param_1;
    *param_1 = bVar2;
    pbVar5 = param_1 + bVar1 + 1;
    for (uVar4 = (uint)bVar3; param_2 = param_2 + 1, uVar4 != 0; uVar4 = uVar4 - 1) {
      *pbVar5 = *param_2;
      pbVar5 = pbVar5 + 1;
    }
  }
  return;
}

