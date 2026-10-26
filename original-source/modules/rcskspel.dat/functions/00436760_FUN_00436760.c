/*
 * FUN_00436760 at 00436760
 * undefined FUN_00436760(void)
 * Address ranges: 00436760-0043697c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00436760(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  bool bVar7;
  bool bVar8;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = (**(code **)*param_1)();
  iVar2 = FUN_00436dc0(param_1[0x10]);
  iVar3 = param_1[0xd];
  bVar8 = SBORROW4(iVar3,-1);
  bVar7 = false;
  if (iVar3 == -1) {
    if (iVar1 == 0) {
      return;
    }
    bVar8 = false;
    bVar7 = true;
  }
  if (!bVar7 && bVar8 == iVar3 + 1 < 0) {
    if ((-1 < iVar2) && (iVar2 < DAT_00508610)) {
      iVar3 = FUN_004365c0();
      puVar4 = *(undefined1 **)(iVar3 + 4);
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      FUN_004afce0(s_Voice__d__m_Voice____VOICE_EFFEC_004ebe90,param_1[0x10],param_1[0xd],puVar4);
    }
    uVar5 = FUN_004365d0();
    FUN_0049dd20(uVar5);
    iVar3 = FUN_0049d870();
    if (iVar3 != 0) {
      FUN_00436980(param_1[0x10],&uStack_c,&uStack_18);
      FUN_0049dd20(uVar5);
      FUN_0049da60(uStack_c,uStack_8,uStack_4,uStack_18,uStack_14,uStack_10,0);
      return;
    }
  }
  if (iVar1 != 0) {
    piVar6 = (int *)(**(code **)(*param_1 + 0xc))();
    param_1[0xd] = *piVar6;
    iVar3 = param_1[4];
    iVar1 = param_1[0xc];
    param_1[4] = iVar3 + 4;
    param_1[0xc] = iVar1 + -1;
    if ((iVar1 + -1 == 0) || (iVar3 + 4 == param_1[3])) {
      FUN_00438c10();
    }
    if ((-1 < iVar2) && (iVar2 < DAT_00508610)) {
      iVar3 = FUN_004365c0();
      puVar4 = *(undefined1 **)(iVar3 + 4);
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      FUN_004afce0(s_Voice__d__m_Voice____VOICE_EFFEC_004ebeec,param_1[0x10],param_1[0xd],puVar4);
    }
    uVar5 = FUN_004365d0();
    FUN_00436980(param_1[0x10],&uStack_18,&uStack_c);
    FUN_0049dd20(uVar5);
    FUN_0049da60(uStack_18,uStack_14,uStack_10,uStack_c,uStack_8,uStack_4,0);
    return;
  }
  if ((-1 < iVar2) && (iVar2 < DAT_00508610)) {
    FUN_004afce0(s_Voice__d__Resetting_004ebed4,param_1[0x10]);
  }
  param_1[0xd] = -1;
  return;
}

