/*
 * FUN_0040d450 at 0040d450
 * undefined __register FUN_0040d450(int * param_1, undefined4 * param_2, byte * param_3)
 * Address ranges: 0040d450-0040d4a0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040d450(int *param_1,undefined4 *param_2,byte *param_3)

{
  byte bVar1;
  code *pcVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar5 = (byte *)param_2[4];
  if ((byte *)param_2[4] == (byte *)0x80000000) {
    pbVar5 = param_3;
  }
  pcVar2 = (code *)param_2[2];
  if (*(byte *)((int)param_2 + 0xb) != 0xff) {
    if (0xfd < *(byte *)((int)param_2 + 0xb)) {
      (**(code **)((int)(short)pcVar2 + *param_1))();
      return;
    }
    (*pcVar2)(param_1,pbVar5);
    return;
  }
  pbVar5 = (byte *)(((uint)pcVar2 & 0xffffff) + (int)param_1);
  bVar1 = *(byte *)(*(int *)*param_2 + 2 + (uint)*(byte *)(*(int *)*param_2 + 1));
  bVar3 = *param_3;
  if (bVar1 <= *param_3) {
    bVar3 = bVar1;
  }
  *pbVar5 = bVar3;
  uVar4 = (uint)bVar3;
  while( true ) {
    pbVar5 = pbVar5 + 1;
    param_3 = param_3 + 1;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    *pbVar5 = *param_3;
  }
  return;
}

