/*
 * FUN_00405d70 at 00405d70
 * undefined __fastcall FUN_00405d70(undefined4 param_1, int param_2)
 * Address ranges: 00405d70-00405d98
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00405d70(undefined4 param_1,int param_2)

{
  uint uVar1;
  int in_EAX;
  uint uVar2;
  
  uVar2 = *(int *)(in_EAX + 0x45c) + param_2;
  uVar1 = *(uint *)(in_EAX + 0x49c);
  *(uint *)(in_EAX + 0x45c) = uVar2;
  if (uVar1 < uVar2) {
    *(uint *)(in_EAX + 0x49c) = uVar2;
  }
  FUN_00402c30(uVar1,param_2,param_2);
  return;
}

