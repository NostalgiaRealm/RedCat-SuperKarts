/*
 * FUN_00432ec4 at 00432ec4
 * int __register FUN_00432ec4(void)
 * Address ranges: 00432ec4-00432fd6;0043300d-00433016
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00432ec4(void)

{
  char cVar1;
  HCURSOR hIcon;
  BOOL BVar2;
  LPBITMAPINFO ptVar3;
  uint uVar4;
  LPVOID pvVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_54;
  undefined1 *puStack_50;
  undefined1 *puStack_4c;
  undefined4 uStack_48;
  ICONINFO *piconinfo;
  ICONINFO local_2c;
  int local_18;
  LPBITMAPINFO local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = (**(code **)PTR_DAT_0047c734)();
  piconinfo = &local_2c;
  hIcon = GetCursor();
  uStack_48 = 0x432eea;
  BVar2 = GetIconInfo(hIcon,piconinfo);
  if (BVar2 != 0) {
    uStack_48 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_48;
    puStack_4c = (undefined1 *)0x432f0e;
    FUN_00419c34(local_2c.hbmMask,&local_c,&local_10);
    puStack_4c = (undefined1 *)0x432f19;
    ptVar3 = (LPBITMAPINFO)FUN_00407c24(local_c + local_10);
    puStack_50 = &LAB_00432fd7;
    uStack_54 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_54;
    pvVar5 = (LPVOID)((int)&(((tagBITMAPINFO *)(ptVar3->bmiColors + -10))->bmiHeader).biSize +
                     local_c);
    puStack_4c = &stack0xfffffffc;
    local_14 = ptVar3;
    cVar1 = FUN_00419cec(local_2c.hbmMask,(HPALETTE)0x0,ptVar3,pvVar5);
    if ((cVar1 != '\0') && ((local_14->bmiHeader).biBitCount == 1)) {
      iVar7 = (ptVar3->bmiHeader).biWidth;
      uVar4 = iVar7 * (uint)(ptVar3->bmiHeader).biBitCount + 0x1f & 0xffffffe0;
      if ((int)uVar4 < 0) {
        uVar4 = uVar4 + 7;
      }
      local_18 = (int)uVar4 >> 3;
      iVar7 = iVar7 * local_18;
      pcVar6 = (char *)((int)pvVar5 + (local_10 - iVar7));
      local_8 = FUN_00432eb4(pcVar6,iVar7,-1);
      if ((local_8 == 0) && ((ptVar3->bmiHeader).biWidth * 2 <= (ptVar3->bmiHeader).biHeight)) {
        local_8 = FUN_00432eb4(pcVar6 + -iVar7,iVar7,'\0');
      }
      local_8 = local_8 / local_18 - local_2c.yHotspot;
    }
    *in_FS_OFFSET = uStack_54;
    puStack_4c = &LAB_00432fde;
    puStack_50 = (undefined1 *)0x432fd6;
    iVar7 = FUN_0040272c((int)local_14);
    return iVar7;
  }
  return local_8;
}

