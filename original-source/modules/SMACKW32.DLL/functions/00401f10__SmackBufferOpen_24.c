/*
 * _SmackBufferOpen@24 at 00401f10
 * uint * __stdcall _SmackBufferOpen@24(HWND param_1, ushort param_2, ushort param_3, uint param_4, ushort param_5, uint param_6)
 * Address ranges: 00401f10-00402762
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * _SmackBufferOpen_24(HWND param_1,ushort param_2,ushort param_3,uint param_4,ushort param_5,
                          uint param_6)

{
  BYTE BVar1;
  DWORD DVar2;
  HDC pHVar3;
  int iVar4;
  int iVar5;
  HPALETTE pHVar6;
  UINT UVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  undefined4 *puVar11;
  HGDIOBJ pvVar12;
  uint *puVar13;
  HINSTANCE hInstance;
  HWND hWnd;
  uint uVar14;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_EDX;
  uint uVar15;
  LOGPALETTE *pLVar16;
  uint uVar17;
  bool bVar18;
  bool bVar19;
  ulonglong uVar20;
  undefined8 uVar21;
  BOOL bForceBkgd;
  LPVOID lpParam;
  LOGPALETTE local_42c [128];
  int aiStack_28 [2];
  undefined4 *puStack_20;
  uint local_1c;
  char local_18;
  byte local_14;
  
                    /* 0x1f10  2  _SmackBufferOpen@24 */
  uVar17 = param_4;
  if (_DAT_0040e808 == 0) {
    DVar2 = GetVersion();
    if ((byte)DVar2 < 4) {
      DAT_00410444 = 0xb0000;
    }
    else {
      DAT_00410444 = 0xa0000;
    }
    pHVar3 = GetDC((HWND)0x0);
    iVar4 = GetDeviceCaps(pHVar3,0xc);
    iVar5 = GetDeviceCaps(pHVar3,0xe);
    _DAT_0040e808 = iVar4 * iVar5;
    if (0x18 < _DAT_0040e808) {
      _DAT_0040e808 = 0x18;
    }
    _DAT_0040e808 = 1 << (DAT_0040e808 & 0x1f);
    if (_DAT_0040e808 < 0x100) {
      DAT_00410468 = (ushort)_DAT_0040e808;
    }
    else {
      DAT_00410468 = 0x100;
    }
    if (_DAT_0040e808 == 0x100) {
      iVar4 = GetDeviceCaps(pHVar3,0x18);
      DAT_0041046c = (ushort)(iVar4 / 2);
    }
    else {
      DAT_0041046c = 0;
    }
    pLVar16 = local_42c;
    puVar11 = &DAT_00410010;
    for (iVar4 = 0x10a; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)puVar11 = 0;
      puVar11 = (undefined4 *)((int)puVar11 + 1);
    }
    uVar15 = 0;
    iVar4 = 0;
    do {
      *(short *)((int)&DAT_00410038 + iVar4) = (short)uVar15;
      uVar15 = uVar15 + 1;
      iVar4 = iVar4 + 2;
    } while (uVar15 < 0x100);
    local_42c[0].palVersion = 0x300;
    local_42c[0].palNumEntries = 0x100;
    for (iVar4 = 0x100; pLVar16 = (LOGPALETTE *)((int)pLVar16 + 4), iVar4 != 0; iVar4 = iVar4 + -1)
    {
      *(undefined4 *)pLVar16 = 0;
    }
    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
      *(undefined1 *)pLVar16 = 0;
      pLVar16 = (LOGPALETTE *)((int)pLVar16 + 1);
    }
    iVar4 = 0;
    do {
      iVar5 = iVar4 + 4;
      (&local_42c[0].palPalEntry[0].peFlags)[iVar4] = '\x04';
      iVar4 = iVar5;
    } while (iVar5 != 0x400);
    bForceBkgd = 1;
    pHVar6 = CreatePalette(local_42c);
    pHVar6 = SelectPalette(pHVar3,pHVar6,bForceBkgd);
    RealizePalette(pHVar3);
    pHVar6 = SelectPalette(pHVar3,pHVar6,1);
    DeleteObject(pHVar6);
    ReleaseDC((HWND)0x0,pHVar3);
  }
  pHVar3 = GetDC((HWND)0x0);
  UVar7 = GetSystemPaletteUse(pHVar3);
  DAT_0041046a = DAT_0041046c;
  if (UVar7 == 2) {
    DAT_0041046a = 1;
  }
  ReleaseDC((HWND)0x0,pHVar3);
  if (param_5 == 0) {
    param_5 = param_3;
  }
  if ((ushort)param_6 == 0) {
    param_6 = param_4;
  }
  if ((param_5 == param_3) && ((ushort)param_6 == (ushort)param_4)) {
    local_14 = 0;
  }
  else {
    local_14 = 1;
  }
  uVar15 = ((uint)param_5 << 2) % (uint)param_3;
  if ((uVar15 == 0) && (uVar15 = ((param_6 & 0xffff) << 2) % (param_4 & 0xffff), uVar15 == 0)) {
    local_18 = '\0';
  }
  else {
    local_18 = '\x01';
  }
  if (param_2 == 0) {
    local_1c = 5;
  }
  else {
    local_1c = param_2 + 1;
  }
  uVar14 = 0;
  do {
    uVar8 = local_1c - 1;
    uVar9 = local_1c - 2;
    uVar20 = CONCAT44(uVar15,uVar9);
    local_1c = uVar8;
    if (3 < (ushort)uVar9) goto switchD_004021d3_default;
    uVar20 = CONCAT44(uVar15,uVar9) & 0xffffffff0000ffff;
    switch(uVar9 & 0xffff) {
    case 0:
      if (param_3 < 0x141) {
        bVar18 = (ushort)param_4 < 0xf0;
        bVar19 = (ushort)param_4 == 0xf0;
LAB_00402207:
        uVar20 = CONCAT44(uVar15,uVar9) & 0xffffffff0000ffff;
        if ((bVar18 || bVar19) &&
           (uVar20 = CONCAT44(uVar15,uVar9) & 0xffffffff0000ffff, (byte)uVar14 == local_14)) {
          uVar20 = FUN_00402aa0(uVar14,uVar15);
          uVar15 = (uint)(uVar20 >> 0x20);
          uVar14 = extraout_ECX_00;
          if ((char)uVar20 != '\0') goto switchD_004021d3_caseD_2;
        }
      }
      break;
    case 1:
      uVar20 = CONCAT44(uVar15,uVar9) & 0xffffffff0000ffff;
      if (param_3 < 0x141) {
        bVar18 = (ushort)param_4 < 200;
        bVar19 = (ushort)param_4 == 200;
        goto LAB_00402207;
      }
      break;
    case 2:
switchD_004021d3_caseD_2:
      uVar21 = FUN_00402c30(uVar14,uVar15,0x478);
      puVar10 = (uint *)uVar21;
      if (puVar10 == (uint *)0x0) {
        return (uint *)0x0;
      }
      puVar13 = puVar10;
      for (iVar4 = 0x11e; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
      for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
        *(undefined1 *)puVar13 = 0;
        puVar13 = (uint *)((int)puVar13 + 1);
      }
      puVar10[2] = local_1c & 0xffff;
      puVar10[4] = (uint)param_3;
      puVar10[5] = param_4 & 0xffff;
      puVar10[6] = puVar10[4] + 3 & 0xfffffffc;
      puVar10[10] = _DAT_0040e808;
      puVar10[8] = (uint)param_5;
      puVar10[9] = param_6 & 0xffff;
      puVar10[7] = (uint)local_14;
      puVar10[0x10f] = 7;
      switch(local_1c - 1 & 0xffff) {
      case 0:
        puVar10[0xb] = 0x100;
        puVar10[0xd] = 0;
        puVar10[0xe] = 0x100;
        puVar10[1] = 1;
        puVar10[3] = 1;
        if ((ushort)param_4 < 0xc9) {
          puVar10[5] = 0xcc;
          param_4 = 0xcc;
        }
        goto LAB_00402339;
      case 1:
        puVar10[0xb] = 0x100;
        puVar10[0xd] = 0;
        puVar10[0xe] = 0x100;
        puVar10[1] = 2;
        puVar10[3] = 1;
        puVar10[4] = 0x140;
        uVar17 = DAT_00410444;
        puVar10[5] = 200;
        puVar10[0x112] = uVar17;
        puVar11 = (undefined4 *)FUN_00402c30(0,(int)((ulonglong)uVar21 >> 0x20),64000);
        puVar10[0x113] = (uint)puVar11;
        for (iVar4 = 16000; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar11 = 0;
          puVar11 = puVar11 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar11 = 0;
          puVar11 = (undefined4 *)((int)puVar11 + 1);
        }
        break;
      case 2:
        puVar10[0xb] = (uint)DAT_00410468;
        uVar15 = (uint)DAT_0041046a;
        puVar10[0xd] = (uint)DAT_0041046a;
        uVar17 = (uint)DAT_00410468;
        puVar10[1] = 1;
        puVar10[0xe] = uVar17 - uVar15 & 0xffff;
        uVar17 = 0;
LAB_00402339:
        *puVar10 = 1;
        uVar17 = FUN_00402c30(uVar17,puVar10[6],(param_4 & 0xffff) * puVar10[6]);
        puVar10[0x112] = uVar17;
        if (uVar17 == 0) {
          FUN_0040650f();
          return (uint *)0x0;
        }
        break;
      case 3:
        puVar10[0xb] = (uint)DAT_00410468;
        uVar17 = (uint)DAT_0041046a;
        puVar10[0xd] = (uint)DAT_0041046a;
        puVar10[0xe] = DAT_00410468 - uVar17 & 0xffff;
        puVar10[1] = (uint)(local_18 != '\0');
        (*DAT_0041045c)(&DAT_00410010);
        *puVar10 = (uint)(-1 < (int)DAT_00410018);
        _DAT_00410014 = puVar10[6];
        DAT_00410018 = DAT_00410018 * param_3;
        uVar17 = (*DAT_00410458)();
        puVar10[0x117] = uVar17;
        if (uVar17 == 0) {
          FUN_0040650f();
          return (uint *)0x0;
        }
        pvVar12 = (HGDIOBJ)(*DAT_00410460)(puVar10[0x117],&DAT_00410010,puVar10 + 0x112);
        puVar10[0x114] = (uint)pvVar12;
        if ((pvVar12 == (HGDIOBJ)0x0) || (puVar10[0x112] == 0)) {
          DeleteDC((HDC)puVar10[0x117]);
          FUN_0040650f();
          return (uint *)0x0;
        }
        pvVar12 = SelectObject((HDC)puVar10[0x117],pvVar12);
        puVar10[0x115] = (uint)pvVar12;
      }
      puVar10[0xc] = (uint)(ushort)((short)puVar10[0xe] - (short)puVar10[0xd]);
      if (puVar10[1] != 2) {
        _SmackBufferClear_8((int)puVar10,0);
      }
      if (_DAT_0040e808 < 0x101) {
        pHVar3 = GetDC((HWND)0x0);
        GetSystemPaletteEntries(pHVar3,0,(uint)(ushort)puVar10[0xb],local_42c[0].palPalEntry);
        ReleaseDC((HWND)0x0,pHVar3);
        uVar17 = 0;
        puVar13 = puVar10;
        if (puVar10[0xb] != 0) {
          do {
            *(BYTE *)((int)puVar13 + 0x3e) = local_42c[0].palPalEntry[uVar17].peRed;
            *(BYTE *)((int)puVar13 + 0x3d) = local_42c[0].palPalEntry[uVar17].peGreen;
            BVar1 = local_42c[0].palPalEntry[uVar17].peBlue;
            *(undefined1 *)((int)puVar13 + 0x3f) = 0;
            *(BYTE *)(puVar13 + 0xf) = BVar1;
            uVar17 = uVar17 + 1;
            puVar13 = puVar13 + 1;
          } while (uVar17 < puVar10[0xb]);
        }
      }
      puVar10[0x119] = (uint)param_1;
      if (puVar10[3] == 0) {
        return puVar10;
      }
      lpParam = (LPVOID)0x0;
      hInstance = (HINSTANCE)GetWindowLongA(param_1,-6);
      hWnd = CreateWindowExA(0,s_DisplayDibWindow_0040e0e0,&DAT_0040e0f4,0x80000000,0,0,0x20,0x20,
                             param_1,(HMENU)0x0,hInstance,lpParam);
      puVar10[0x11c] = (uint)hWnd;
      if (hWnd != (HWND)0x0) {
        DAT_00410440 = puVar10;
        uVar17 = SetWindowLongA(hWnd,-4,0x402770);
        puVar10[0x11b] = uVar17;
        uVar17 = SetWindowLongA((HWND)puVar10[0x119],-4,0x4028a0);
        puVar10[0x11a] = uVar17;
        DAT_00410010 = 0x28;
        _DAT_00410020 = 0;
        _DAT_00410014 = puVar10[6];
        _DAT_0041001c = 1;
        DAT_00410018 = puVar10[5];
        _DAT_0041001e = 8;
        if (puVar10[2] == 1) {
          uVar17 = 5;
        }
        else {
          uVar17 = 1;
        }
        aiStack_28[0] = (uVar17 | 0x8ad0) * 0x10000 + 0x400;
        puStack_20 = &DAT_00410010;
        aiStack_28[1] = 0x428;
        SendMessageA((HWND)puVar10[0x11c],0x4a,0,(LPARAM)aiStack_28);
        ShowWindow((HWND)puVar10[0x119],6);
        ShowWindow((HWND)puVar10[0x11c],1);
        return puVar10;
      }
      FUN_0040650f();
      FUN_0040650f();
      return (uint *)0x0;
    case 3:
      if (uVar14 == DAT_0040e800) {
        FUN_00402b00();
        uVar14 = extraout_ECX;
        uVar15 = extraout_EDX;
      }
      uVar20 = (ulonglong)uVar15 << 0x20;
      if (0x1f < DAT_0040e800) goto switchD_004021d3_caseD_2;
    }
switchD_004021d3_default:
    uVar15 = (uint)(uVar20 >> 0x20);
    if (param_2 != 0) {
      return (uint *)0x0;
    }
  } while( true );
}

