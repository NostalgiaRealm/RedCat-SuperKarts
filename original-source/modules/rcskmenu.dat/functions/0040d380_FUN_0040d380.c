/*
 * FUN_0040d380 at 0040d380
 * uint __register FUN_0040d380(int * param_1, undefined4 * param_2)
 * Address ranges: 0040d380-0040d3f0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_0040d380(int *param_1,undefined4 *param_2)

{
  char *pcVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  byte bVar6;
  
  pcVar1 = *(char **)*param_2;
  bVar6 = 4;
  if (*pcVar1 != '\a') {
    bVar6 = pcVar1[(byte)pcVar1[1] + 2];
  }
  pcVar2 = (code *)param_2[1];
  if (*(byte *)((int)param_2 + 7) < 0xfe) {
    uVar3 = (*pcVar2)(param_1,param_2[4]);
  }
  else if (*(byte *)((int)param_2 + 7) == 0xff) {
    puVar5 = (uint *)(((uint)pcVar2 & 0xffffff) + (int)param_1);
    uVar3 = CONCAT31((int3)((uint)param_1 >> 8),(char)*puVar5);
    if ((1 < bVar6) && (uVar3 = CONCAT22((short)((uint)param_1 >> 0x10),(short)*puVar5), 3 < bVar6))
    {
      uVar3 = *puVar5;
    }
  }
  else {
    uVar3 = (**(code **)((int)(short)pcVar2 + *param_1))();
  }
  uVar4 = uVar3;
  if (bVar6 < 4) {
    if (bVar6 < 2) {
      uVar4 = (uint)(char)uVar3;
      if (bVar6 != 0) {
        return uVar3 & 0xff;
      }
    }
    else {
      uVar4 = (uint)(short)uVar3;
      if (bVar6 != 2) {
        uVar4 = uVar3 & 0xffff;
      }
    }
  }
  return uVar4;
}

