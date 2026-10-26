/*
 * FUN_0043f134 at 0043f134
 * undefined __register FUN_0043f134(int param_1, int * param_2)
 * Address ranges: 0043f134-0043f1b4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f134(int param_1,int *param_2)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffd4;
  undefined4 *puVar3;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  byte *local_10;
  undefined4 local_c;
  undefined1 local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_10 = (byte *)0x0;
  puStack_20 = &LAB_0043f1b5;
  puStack_24 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_24;
  puVar1 = &stack0xfffffffc;
  if (*(int *)(param_1 + 0x24) == 0) {
    local_c = *(undefined4 *)(param_1 + 8);
    local_8 = 0xb;
    puVar3 = &local_c;
    in_stack_ffffffd4 = 0;
    FUN_00405438((undefined4 *)PTR_PTR_0047c8a8,(int *)&local_10);
    uVar2 = FUN_0040aca0((int)&DAT_0040de0c,'\x01',local_10,in_stack_ffffffd4,puVar3);
    FUN_00403604(uVar2);
    puVar1 = puStack_1c;
  }
  puStack_1c = puVar1;
  (**(code **)(**(int **)(param_1 + 0x24) + 0x3c))(*(int **)(param_1 + 0x24),param_2);
  *param_2 = *param_2 + *(int *)(param_1 + 0x30);
  param_2[1] = param_2[1] + *(int *)(param_1 + 0x34);
  *in_FS_OFFSET = in_stack_ffffffd4;
  puStack_24 = &LAB_0043f1bc;
  FUN_00403b50((int *)&local_10);
  return;
}

