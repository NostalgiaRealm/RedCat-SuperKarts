/*
 * FUN_0048c9a0 at 0048c9a0
 * undefined FUN_0048c9a0(void)
 * Address ranges: 0048c9a0-0048ca55
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0048c9a0(int param_1,int param_2,undefined1 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  *(int *)(param_1 + 0x1180) = param_2;
  iVar2 = DAT_006a5c38 + *(int *)(param_2 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9;
  *(undefined4 *)(param_1 + 0x1184) = *(undefined4 *)(iVar2 + 0x50);
  *(undefined4 *)(param_1 + 0x1188) = *(undefined4 *)(iVar2 + 0x54);
  *(undefined4 *)(param_1 + 0x118c) = *(undefined4 *)(iVar2 + 0x58);
  puVar1 = (undefined4 *)(param_2 * 0xd0 + 0x9c + DAT_0067ee20);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  *(undefined4 *)(param_1 + 0x1190) = 0;
  *(undefined4 *)(param_1 + 0x1194) = 0;
  *(undefined1 *)(param_1 + 0x11a0) = 0;
  *(undefined1 *)(param_1 + 0x1198) = 1;
  *(undefined1 *)(param_1 + 0x11ac) = param_3;
  return;
}

