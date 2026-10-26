/*
 * FUN_00450fd4 at 00450fd4
 * undefined __register FUN_00450fd4(void)
 * Address ranges: 00450fd4-004510bf
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00450fd4(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  int in_stack_00000004;
  int local_10;
  
  puVar6 = *(undefined4 **)(*(int *)(in_stack_00000004 + -8) + 0x440);
  pbVar5 = *(byte **)(*(int *)(in_stack_00000004 + -4) + 0x440);
  local_10 = 0;
  do {
    bVar1 = *pbVar5;
    bVar2 = pbVar5[1];
    pbVar4 = pbVar5 + 2;
    if (bVar1 == 0) {
      if (bVar2 == 0) {
        local_10 = local_10 + 1;
        puVar6 = (undefined4 *)
                 (*(int *)(*(int *)(in_stack_00000004 + -8) + 0x440) +
                 *(int *)(*(int *)(in_stack_00000004 + -8) + 0x480) * local_10);
      }
      else {
        if (bVar2 == 1) {
          return;
        }
        if (bVar2 == 2) {
          local_10 = local_10 + 2;
          pbVar4 = pbVar5 + 4;
          puVar6 = (undefined4 *)
                   (*(int *)(*(int *)(in_stack_00000004 + -8) + 0x440) +
                   *(int *)(*(int *)(in_stack_00000004 + -8) + 0x480) * local_10);
        }
        else {
          uVar3 = (uint)bVar2;
          FUN_0040282c((undefined4 *)pbVar4,puVar6,uVar3);
          puVar6 = (undefined4 *)((int)puVar6 + uVar3);
          pbVar4 = pbVar4 + uVar3;
        }
      }
    }
    else {
      FUN_00402b54(puVar6,(uint)bVar1,bVar2);
      puVar6 = (undefined4 *)((int)puVar6 + (uint)bVar1);
    }
    pbVar5 = pbVar4 + ((uint)pbVar4 & 1);
  } while( true );
}

