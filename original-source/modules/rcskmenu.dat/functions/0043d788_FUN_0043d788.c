/*
 * FUN_0043d788 at 0043d788
 * undefined __register FUN_0043d788(POINT * param_1)
 * Address ranges: 0043d788-0043da58
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043d788(POINT *param_1)

{
  char cVar1;
  bool bVar2;
  undefined1 uVar3;
  short sVar4;
  uint uVar5;
  int *piVar6;
  HWND pHVar7;
  HCURSOR pHVar8;
  undefined4 uVar9;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar10;
  uint uVar11;
  int *piVar12;
  byte bVar13;
  LONG LVar14;
  int local_1c;
  bool local_18 [4];
  int local_14;
  int local_10;
  
  bVar13 = 0;
  if (((DAT_0047d7d8 == '\0') &&
      (uVar5 = DAT_0047d7c8 - param_1->x, uVar11 = (int)uVar5 >> 0x1f,
      (int)((uVar5 ^ uVar11) - uVar11) < DAT_0047d7d4)) &&
     (uVar5 = DAT_0047d7cc - param_1->y, uVar11 = (int)uVar5 >> 0x1f,
     (int)((uVar5 ^ uVar11) - uVar11) < DAT_0047d7d4)) {
    return;
  }
  piVar6 = FUN_0043d668(param_1,&local_1c,*(char *)((int)DAT_0047d7b8 + 0x8b),DAT_0047d7b8);
  if ((DAT_0047d7d8 == '\0') && (DAT_0047d7dc != (int *)0x0)) {
    iVar10 = DAT_0047d7cc;
    pHVar7 = GetDesktopWindow();
    FUN_00446ee4(DAT_0047d7dc,pHVar7,DAT_0047d7c8,iVar10);
  }
  cVar1 = DAT_0047d7d8;
  local_18[0] = *(char *)((int)DAT_0047d7b8 + 0x8b) != '\0';
  if (local_18[0]) {
    DAT_0047d7d8 = '\x02';
  }
  else {
    DAT_0047d7d8 = '\x01';
  }
  local_18[0] = local_18[0] && cVar1 != '\0';
  if (piVar6 != (int *)DAT_0047d7bc[1]) {
    FUN_0043d6b8(CONCAT31((int3)((uint)DAT_0047d7bc >> 8),1));
    if (DAT_0047d7bc == (int *)0x0) {
      return;
    }
    DAT_0047d7bc[1] = (int)piVar6;
    DAT_0047d7bc[2] = local_1c;
    piVar12 = DAT_0047d7bc;
    DAT_0047d7bc[3] = param_1->x;
    piVar12[4] = param_1->y;
    FUN_0043d6b8(0);
    if (DAT_0047d7bc == (int *)0x0) {
      return;
    }
  }
  piVar12 = DAT_0047d7bc;
  DAT_0047d7bc[3] = param_1->x;
  piVar12[4] = param_1->y;
  if (DAT_0047d7bc[1] != 0) {
    FUN_0043f1f0((int *)DAT_0047d7bc[1],&param_1->x,&local_14);
    piVar12 = DAT_0047d7bc;
    DAT_0047d7bc[5] = local_14;
    piVar12[6] = local_10;
  }
  LVar14 = param_1->y;
  bVar2 = FUN_0043d6b8(CONCAT31((int3)((uint)LVar14 >> 8),2));
  sVar4 = (**(code **)(*DAT_0047d7bc + 4))(DAT_0047d7bc,bVar2,param_1->x,LVar14);
  if (DAT_0047d7dc != (int *)0x0) {
    if ((piVar6 == (int *)0x0) || ((*(byte *)((int)piVar6 + 0x41) & 0x20) != 0)) {
      FUN_00446ecc((int)DAT_0047d7dc,sVar4);
      if (*(char *)((int)DAT_0047d7dc + 0x62) == '\0') {
        LVar14 = param_1->y;
        pHVar7 = GetDesktopWindow();
        FUN_00446ee4(DAT_0047d7dc,pHVar7,param_1->x,LVar14);
      }
      else {
        FUN_00446fcc((int)DAT_0047d7dc,param_1->x,param_1->y);
      }
    }
    else {
      FUN_00447040((int)DAT_0047d7dc);
      pHVar8 = (HCURSOR)FUN_00430608(*(int *)PTR_DAT_0047c9bc,(int)sVar4);
      SetCursor(pHVar8);
    }
  }
  pHVar8 = (HCURSOR)FUN_00430608(*(int *)PTR_DAT_0047c9bc,(int)sVar4);
  SetCursor(pHVar8);
  if (DAT_0047d7d8 == '\x02') {
    if (piVar6 == (int *)0x0) {
      FUN_00403088((int *)DAT_0047d7bc[0xe],DAT_0047d7bc,param_1->x);
    }
    else {
      piVar6 = (int *)FUN_0043d6f4();
      DAT_0047d7bc[0x16] = (int)piVar6;
      if (piVar6 == (int *)0x0) {
        uVar3 = FUN_00403088((int *)DAT_0047d7bc[1],DAT_0047d7bc + 5,extraout_ECX);
        *(undefined1 *)(DAT_0047d7bc + 0x15) = uVar3;
      }
      else {
        FUN_0043f1f0(piVar6,&param_1->x,(int *)local_18);
        uVar3 = FUN_00403088(piVar6,local_18,extraout_ECX_00);
        *(undefined1 *)(DAT_0047d7bc + 0x15) = uVar3;
      }
    }
    if ((DAT_0047d7bc != (int *)0x0) &&
       (uVar9 = FUN_00407ce4(DAT_0047d7bc + 0x11,DAT_0047d7bc + 0x17,0x10), (char)uVar9 == '\0')) {
      if ((char)local_1c != '\0') {
        (**(code **)(*DAT_0047d7bc + 0x30))();
      }
      (**(code **)(*DAT_0047d7bc + 0x2c))();
      piVar6 = DAT_0047d7bc + 0x11;
      piVar12 = DAT_0047d7bc + 0x17;
      for (iVar10 = 4; iVar10 != 0; iVar10 = iVar10 + -1) {
        *piVar12 = *piVar6;
        piVar6 = piVar6 + (uint)bVar13 * -2 + 1;
        piVar12 = piVar12 + (uint)bVar13 * -2 + 1;
      }
    }
  }
  return;
}

