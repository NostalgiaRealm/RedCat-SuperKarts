/*
 * FUN_004233e4 at 004233e4
 * undefined FUN_004233e4(void)
 * Address ranges: 004233e4-00423539
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004233e4(int *param_1,LPRECT param_2,uint param_3)

{
  char cVar1;
  uint format;
  int iVar2;
  LPCSTR pCVar3;
  HDC pHVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar5;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 *in_FS_OFFSET;
  LPRECT lprc;
  uint format_00;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  char *pcStack_8;
  
  puStack_18 = &stack0xfffffffc;
  pcStack_8 = (char *)0x0;
  puStack_1c = &LAB_0042353a;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  (**(code **)(*param_1 + 0x88))(param_1,&pcStack_8);
  uVar5 = extraout_ECX;
  if (((param_3 & 0x400) != 0) &&
     ((pcStack_8 == (char *)0x0 ||
      ((((char)param_1[0x4c] != '\0' && (*pcStack_8 == '&')) && (pcStack_8[1] == '\0')))))) {
    FUN_00403dd8((int *)&pcStack_8,(undefined4 *)&DAT_00423550);
    uVar5 = extraout_ECX_00;
  }
  if ((char)param_1[0x4c] == '\0') {
    param_3 = param_3 | 0x800;
  }
  format = FUN_00441538(param_1,param_3,uVar5);
  FUN_004188b4(param_1[0x48]);
  cVar1 = (**(code **)(*param_1 + 0x4c))();
  if (cVar1 == '\0') {
    OffsetRect(param_2,1,1);
    FUN_004176d0(*(int **)(param_1[0x48] + 0xc),-0x7fffffec,extraout_ECX_01);
    lprc = param_2;
    format_00 = format;
    iVar2 = FUN_00403dd0((int)pcStack_8);
    pCVar3 = FUN_00403f94(pcStack_8);
    pHVar4 = (HDC)FUN_00418994((int *)param_1[0x48]);
    DrawTextA(pHVar4,pCVar3,iVar2,lprc,format_00);
    OffsetRect(param_2,-1,-1);
    FUN_004176d0(*(int **)(param_1[0x48] + 0xc),-0x7ffffff0,extraout_ECX_02);
    iVar2 = FUN_00403dd0((int)pcStack_8);
    pCVar3 = FUN_00403f94(pcStack_8);
    pHVar4 = (HDC)FUN_00418994((int *)param_1[0x48]);
    DrawTextA(pHVar4,pCVar3,iVar2,param_2,format);
  }
  else {
    iVar2 = FUN_00403dd0((int)pcStack_8);
    pCVar3 = FUN_00403f94(pcStack_8);
    pHVar4 = (HDC)FUN_00418994((int *)param_1[0x48]);
    DrawTextA(pHVar4,pCVar3,iVar2,param_2,format);
  }
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_00423541;
  puStack_1c = (undefined1 *)0x423539;
  FUN_00403b50((int *)&pcStack_8);
  return;
}

