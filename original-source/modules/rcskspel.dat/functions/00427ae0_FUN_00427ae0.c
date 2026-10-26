/*
 * FUN_00427ae0 at 00427ae0
 * undefined FUN_00427ae0(void)
 * Address ranges: 00427ae0-00427bbc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00427ae0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  _DAT_0052d5b0 = 0xffffff;
  _DAT_0052d5d0 = 0xffffff;
  _DAT_0052d5f0 = 0xffffff;
  DAT_0052d5a0 = 0xbe666666;
  _DAT_0052d5a8 = 0;
  DAT_0052d5a4 = 0xbe666666;
  _DAT_0052d5b4 = 0;
  _DAT_0052d5b8 = 0x3f4e8d76;
  _DAT_0052d5bc = 0x3e3d744f;
  DAT_0052d5c0 = 0;
  _DAT_0052d5c8 = 0;
  DAT_0052d5c4 = 0x3e666666;
  _DAT_0052d5d4 = 0;
  _DAT_0052d5d8 = 0x3f4e8d76;
  _DAT_0052d5dc = 0;
  DAT_0052d5e0 = 0x3e666666;
  _DAT_0052d5e8 = 0;
  DAT_0052d5e4 = 0xbe666666;
  _DAT_0052d5f4 = 0;
  _DAT_0052d5f8 = 0x3f7dea89;
  _DAT_0052d5fc = 0;
  puVar2 = &DAT_0052d5e0;
  puVar3 = &DAT_0052d600;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = &DAT_0052d5c0;
  puVar3 = &DAT_0052d620;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = &DAT_0052d5a0;
  puVar3 = &DAT_0052d640;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}

