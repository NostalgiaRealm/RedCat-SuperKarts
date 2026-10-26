/*
 * FUN_00402a00 at 00402a00
 * undefined __stdcall FUN_00402a00(void)
 * Address ranges: 00402a00-00402a91
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00402a00(void)

{
  int in_EAX;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_24 [2];
  undefined4 *local_1c;
  
  puVar4 = (undefined4 *)(in_EAX + 0x3c);
  puVar5 = (undefined4 *)&DAT_00410038;
  for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  if (*(int *)(in_EAX + 8) == 1) {
    uVar1 = 5;
  }
  else {
    uVar1 = 1;
  }
  local_24[0] = (uVar1 | 0x8ac0) * 0x10000 + 0x400;
  local_24[1] = 0x428;
  local_1c = &DAT_00410010;
  SendMessageA(*(HWND *)(in_EAX + 0x470),0x4a,0,(LPARAM)local_24);
  iVar2 = 0;
  iVar3 = 0;
  do {
    *(short *)((int)&DAT_00410038 + iVar3) = (short)iVar2;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 2;
  } while (iVar2 < 0x100);
  return;
}

