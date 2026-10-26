/*
 * FUN_0044cd50 at 0044cd50
 * undefined FUN_0044cd50(void)
 * Address ranges: 0044cd50-0044ce5f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0044cd50(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  char *pcVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  
  *(int *)(param_1 + 0x68) = param_2;
  puVar3 = *(undefined1 **)(param_1 + 0x18);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  param_2 = FUN_004a3040(puVar3);
  if (param_2 < 0) {
    puVar3 = *(undefined1 **)(param_1 + 0x18);
    if (DAT_0053b9f0 == 0) {
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_004d2404;
      }
      param_2 = FUN_0049b300(puVar3,0,0);
      uVar5 = 0xffffffff;
      pcVar8 = s_char_rc_004f07a0;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      uVar2 = *(uint *)(param_1 + 0x1c);
      uVar6 = ~uVar5 - 1;
      uVar5 = uVar2;
      if (uVar6 <= uVar2) {
        uVar5 = uVar6;
      }
      bVar10 = false;
      iVar4 = 0;
      bVar11 = true;
      pbVar7 = *(byte **)(param_1 + 0x18);
      pbVar9 = (byte *)s_char_rc_004f07a0;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        bVar10 = *pbVar7 < *pbVar9;
        bVar11 = *pbVar7 == *pbVar9;
        pbVar7 = pbVar7 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar11);
      if (!bVar11) {
        iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      }
      if (((iVar4 == 0) && (uVar6 <= uVar2)) && (uVar2 == uVar6)) {
        puVar3 = *(undefined1 **)(param_1 + 0x18);
        if (puVar3 == (undefined1 *)0x0) {
          puVar3 = &DAT_004d2404;
        }
        FUN_004afce0(s_____Unaccelerated___s___d__004f07a8,puVar3,param_2);
      }
    }
    else {
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_004d2404;
      }
      param_2 = FUN_0049b300(puVar3,1,1);
    }
  }
  iVar4 = FUN_004906b0(4);
  *(int *)(DAT_006a5c38 + iVar4 * 0xa9 + 0x95) = param_2;
  return;
}

