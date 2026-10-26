/*
 * FUN_00406330 at 00406330
 * undefined FUN_00406330(void)
 * Address ranges: 00406330-0040641f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00406330(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  DWORD DVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  for (puVar1 = DAT_0040e860; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[0xd]) {
    if ((((uint)puVar1[0x19] < (uint)puVar1[4]) || ((puVar1[0x11] != 0 && (3 < (uint)puVar1[4]))))
       && (uVar2 = (*DAT_004104b4)(puVar1[0xe]), uVar2 < 2)) {
      uVar6 = puVar1[4] & 0xfffffffc;
      if ((uint)puVar1[0xf] < uVar6) {
        uVar6 = puVar1[0xf] & 0xfffffffc;
      }
      if ((puVar1[0x1b] == 0) || (iVar3 = (*DAT_004104a0)(puVar1[0xe],0,0,0,0), iVar3 != 0)) {
        DVar4 = timeGetTime();
        puVar1[0x1b] = DVar4;
        iVar3 = puVar1[0x1a];
        puVar1[0x1a] = 0;
        puVar1[0x14] = puVar1[0x14] + iVar3;
      }
      puVar5 = FUN_00402c70(uVar6,puVar1[1],(undefined4 *)*puVar1,(undefined4 *)puVar1[2],
                            (undefined4 *)puVar1[uVar2 + 0x15]);
      puVar1[2] = puVar5;
      (*DAT_004104b8)(puVar1[0xe],uVar2,puVar1[uVar2 + 0x15],uVar6);
      puVar1[0x1a] = puVar1[0x1a] + uVar6;
      puVar1[4] = puVar1[4] - uVar6;
    }
  }
  (*DAT_004104c0)();
  return;
}

