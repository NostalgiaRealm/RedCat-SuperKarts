/*
 * FUN_0048af00 at 0048af00
 * undefined FUN_0048af00(void)
 * Address ranges: 0048af00-0048aff1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0048af00(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar1 = param_2;
  FUN_0048baa0(param_2);
  iVar4 = param_2 - param_1;
  param_2 = 7;
  puVar2 = (undefined4 *)(param_1 + 8);
  do {
    puVar5 = (undefined4 *)(iVar4 + (int)puVar2);
    puVar6 = puVar2;
    for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    param_2 = param_2 + -1;
    puVar2 = puVar2 + 8;
  } while (param_2 != 0);
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(iVar1 + 0xe8);
  *(undefined1 *)(param_1 + 0xec) = *(undefined1 *)(iVar1 + 0xec);
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(iVar1 + 0xf0);
  *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(iVar1 + 0xf4);
  *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(iVar1 + 0xf8);
  *(undefined4 *)(param_1 + 0xfc) = *(undefined4 *)(iVar1 + 0xfc);
  *(undefined1 *)(param_1 + 0x100) = *(undefined1 *)(iVar1 + 0x100);
  *(undefined1 *)(param_1 + 0x101) = *(undefined1 *)(iVar1 + 0x101);
  *(undefined1 *)(param_1 + 0x102) = *(undefined1 *)(iVar1 + 0x102);
  *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(iVar1 + 0x104);
  *(undefined1 *)(param_1 + 0x108) = *(undefined1 *)(iVar1 + 0x108);
  *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(iVar1 + 0x10c);
  *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(iVar1 + 0x110);
  *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(iVar1 + 0x114);
  *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(iVar1 + 0x118);
  *(undefined1 *)(param_1 + 0x11c) = *(undefined1 *)(iVar1 + 0x11c);
  return param_1;
}

