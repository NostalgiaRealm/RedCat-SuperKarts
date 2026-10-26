/*
 * FUN_0043d414 at 0043d414
 * int * __register FUN_0043d414(LONG * param_1, int * param_2)
 * Address ranges: 0043d414-0043d55d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0043d414(LONG *param_1,int *param_2)

{
  POINT pt;
  char cVar1;
  bool bVar2;
  ushort uVar3;
  HWND hWnd;
  BOOL BVar4;
  int iVar5;
  undefined1 *extraout_ECX;
  undefined1 *extraout_ECX_00;
  undefined1 *extraout_ECX_01;
  undefined1 *extraout_ECX_02;
  undefined1 *extraout_ECX_03;
  undefined1 *extraout_ECX_04;
  undefined1 *extraout_ECX_05;
  undefined1 *extraout_ECX_06;
  undefined1 *puVar6;
  undefined1 *extraout_ECX_07;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 uVar7;
  undefined4 extraout_EDX_08;
  int iVar8;
  int iVar9;
  RECT local_2c;
  int *local_1c;
  int *local_18;
  int *local_14;
  LONG local_10;
  LONG local_c;
  char local_5;
  
  local_10 = *param_1;
  local_c = param_1[1];
  local_1c = (int *)0x0;
  local_14 = param_2;
  uVar3 = GetKeyState(0x11);
  if ((uVar3 & 0x8000) == 0 && DAT_0047d7e0 != (undefined4 *)0x0) {
    (**(code **)(*DAT_0047d7e4 + 8))();
    iVar8 = DAT_0047d7e0[2];
    puVar6 = extraout_ECX;
    uVar7 = extraout_EDX;
    if (-1 < iVar8 + -1) {
      iVar9 = 0;
      do {
        local_18 = (int *)FUN_0040f6b0(DAT_0047d7e0,iVar9);
        puVar6 = extraout_ECX_00;
        uVar7 = extraout_EDX_00;
        if ((local_18 != local_14) && ((char)local_18[0x5a] != '\0')) {
          cVar1 = (**(code **)(*local_18 + 0x4c))();
          puVar6 = extraout_ECX_01;
          uVar7 = extraout_EDX_01;
          if (cVar1 != '\0') {
            hWnd = (HWND)FUN_00445724(local_18);
            BVar4 = IsWindowVisible(hWnd);
            puVar6 = extraout_ECX_02;
            uVar7 = extraout_EDX_02;
            if (BVar4 != 0) {
              puVar6 = &stack0xfffffffc;
              bVar2 = FUN_0043d3d0();
              uVar7 = extraout_EDX_03;
              if (!bVar2) {
                if ((int *)local_14[0x24] == local_18) {
                  iVar5 = FUN_004440b0((int)local_18);
                  puVar6 = extraout_ECX_03;
                  uVar7 = extraout_EDX_04;
                  if (iVar5 < 2) goto LAB_0043d51b;
                }
                local_5 = '\x01';
                FUN_00403088(local_18,local_14,&local_2c);
                puVar6 = extraout_ECX_04;
                uVar7 = extraout_EDX_05;
                if (local_5 != '\0') {
                  pt.y = local_c;
                  pt.x = local_10;
                  BVar4 = PtInRect(&local_2c,pt);
                  puVar6 = extraout_ECX_05;
                  uVar7 = extraout_EDX_06;
                  if (BVar4 != 0) {
                    FUN_0043cc1c(DAT_0047d7e4,local_18);
                    puVar6 = extraout_ECX_06;
                    uVar7 = extraout_EDX_07;
                  }
                }
              }
            }
          }
        }
LAB_0043d51b:
        iVar9 = iVar9 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    if (0 < DAT_0047d7e4[2]) {
      local_1c = (int *)FUN_0043ccac(DAT_0047d7e4,uVar7,(int)puVar6);
      puVar6 = extraout_ECX_07;
      uVar7 = extraout_EDX_08;
    }
    if (local_1c != (int *)0x0) {
      cVar1 = FUN_0043d238(local_1c,uVar7,puVar6,(int)&stack0xfffffffc);
      if (cVar1 == '\0') {
        local_1c = (int *)0x0;
      }
    }
  }
  return local_1c;
}

