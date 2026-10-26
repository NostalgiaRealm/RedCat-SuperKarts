/*
 * _SmackOpen@12 at 00404900
 * int * __stdcall _SmackOpen@12(int * param_1, uint param_2, uint param_3)
 * Address ranges: 00404900-00405151
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * _SmackOpen_12(int *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  int *piVar2;
  uint *puVar3;
  DWORD DVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar5;
  uint extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 uVar6;
  uint extraout_ECX_10;
  uint extraout_ECX_11;
  uint extraout_ECX_12;
  uint extraout_ECX_13;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar7;
  uint uVar8;
  uint extraout_EDX_01;
  uint extraout_EDX_02;
  uint extraout_EDX_03;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ulonglong uVar12;
  uint *local_2c;
  DWORD local_28;
  DWORD local_24;
  int *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
                    /* 0x4900  14  _SmackOpen@12 */
  uVar10 = 0;
  local_14 = 0;
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  local_24 = timeGetTime();
  if ((param_2 & 0x1000) == 0) {
    local_20 = CreateFileA((LPCSTR)param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000080,
                           (HANDLE)0x0);
    local_28 = 0;
    uVar6 = extraout_ECX_00;
    uVar7 = extraout_EDX_00;
  }
  else {
    local_20 = param_1;
    if ((param_2 & 0x2000000) != 0) {
      local_20 = (int *)*param_1;
    }
    local_28 = SetFilePointer(local_20,0,(PLONG)0x0,1);
    uVar6 = extraout_ECX;
    uVar7 = extraout_EDX;
  }
  if (local_20 == (int *)0xffffffff) {
    return (int *)0x0;
  }
  if (((param_2 & 0x2000000) == 0) &&
     (param_1 = (int *)FUN_00402c30(uVar6,uVar7,0x4ac), param_1 == (int *)0x0)) {
    return (int *)0x0;
  }
  piVar2 = param_1;
  for (iVar5 = 299; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar2 = 0;
    piVar2 = piVar2 + 1;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined1 *)piVar2 = 0;
    piVar2 = (int *)((int)piVar2 + 1);
  }
  param_1[0x117] = 0x4ac;
  param_1[0xe5] = (int)local_20;
  param_1[0xea] = local_28;
  if ((param_2 & 0x800) != 0) {
    param_1[0x128] = DAT_0040e844;
  }
  local_28 = 0;
  *param_1 = 0;
  FUN_004059b0(0,param_1);
  if (*param_1 != 0x324b4d53) goto LAB_00404a15;
  if ((param_2 & 0x80) != 0) {
    param_1[4] = DAT_0040e848;
  }
  iVar5 = param_1[4];
  if (iVar5 < 0) {
    iVar5 = -iVar5;
  }
  else {
    iVar5 = iVar5 * 100;
  }
  param_1[0x100] = iVar5;
  if (iVar5 == 0) {
    local_18 = 100000;
    uVar8 = extraout_ECX_01;
  }
  else {
    uVar8 = param_1[0x100];
    local_18 = (uint)(100000 / (ulonglong)uVar8);
  }
  if (local_18 == 0) {
    local_18 = 1;
  }
  local_28 = param_1[3] + (param_1[5] & 1U);
  iVar5 = local_28 * 5 + 4;
  uVar11 = param_1[0x117] + iVar5;
  param_1[0x117] = uVar11;
  if ((uint)param_1[0x127] < uVar11) {
    param_1[0x127] = uVar11;
  }
  iVar5 = FUN_00402c30(uVar8,iVar5,iVar5);
  param_1[0xef] = iVar5;
  if (iVar5 == 0) goto LAB_00404a15;
  param_1[0xee] = (int)(local_28 + iVar5);
  FUN_004059b0(extraout_ECX_02,(undefined4 *)(local_28 + iVar5));
  FUN_004059b0(extraout_ECX_03,(undefined4 *)param_1[0xef]);
  param_1[0xea] = param_1[0xea] + local_28 * 5;
  iVar5 = FUN_00409c90();
  iVar5 = iVar5 + param_1[0xe] + param_1[0xf] + param_1[0x10] + param_1[0x11];
  uVar8 = param_1[0x127];
  uVar11 = param_1[0x117] + iVar5;
  param_1[0x117] = uVar11;
  if (uVar8 < uVar11) {
    param_1[0x127] = uVar11;
  }
  iVar5 = FUN_00402c30(uVar8,iVar5,iVar5);
  param_1[0xe7] = iVar5;
  if (iVar5 == 0) {
    FUN_00402c10();
    goto LAB_00404a15;
  }
  uVar8 = param_1[0xd] + 0x1003U & 0xfffffffc;
  if (uVar8 < 0x2000) {
    uVar8 = 0x2000;
  }
  uVar11 = param_1[0x117] + uVar8;
  param_1[0x117] = uVar11;
  if ((uint)param_1[0x127] < uVar11) {
    param_1[0x127] = uVar11;
  }
  piVar2 = (int *)FUN_00402c30(uVar11,uVar8,uVar8);
  if (piVar2 != (int *)0x0) {
    FUN_004059b0(extraout_ECX_04,piVar2 + 0x400);
    FUN_00409ca0((void *)param_1[0xe],piVar2,(undefined4 *)param_1[0xe7],(void *)param_1[0xe],
                 param_1[0xf],param_1[0x10],param_1[0x11]);
    FUN_00402c10();
    param_1[0x117] = param_1[0x117] - (param_1[0xd] + 0x1000);
    param_1[0xea] = param_1[0xea] + param_1[0xd] + 0x68;
    local_28 = param_1[3] + -1 + (param_1[5] & 1U);
    uVar8 = 0;
    puVar3 = (uint *)param_1[0xee];
    if (local_28 < local_18) {
      local_1c = 0;
      uVar9 = 0;
      do {
        uVar11 = *puVar3;
        uVar8 = uVar8 + uVar11;
        if (local_14 < uVar11) {
          local_14 = uVar11;
        }
        uVar11 = *puVar3;
        puVar3 = puVar3 + 1;
        uVar9 = uVar9 + 1;
        uVar10 = uVar10 + uVar11;
      } while (uVar9 <= local_28);
    }
    else {
      uVar11 = 0;
      uVar9 = 0;
      if (local_18 != 0) {
        do {
          uVar9 = uVar9 + 1;
          uVar11 = uVar11 + *puVar3;
          puVar3 = puVar3 + 1;
        } while (uVar9 < local_18);
      }
      puVar3 = (uint *)param_1[0xee];
      uVar9 = 0;
      local_2c = puVar3 + local_18;
      do {
        if ((uVar8 < uVar11) && (uVar9 != 0)) {
          uVar8 = uVar11;
          local_1c = uVar9;
        }
        uVar11 = (uVar11 - *puVar3) + *local_2c;
        if (local_14 < *puVar3) {
          local_14 = *puVar3;
        }
        uVar10 = uVar10 + *puVar3;
        local_2c = local_2c + 1;
        uVar9 = uVar9 + 1;
        puVar3 = puVar3 + 1;
      } while (uVar9 <= local_28 - local_18);
      for (; uVar9 <= local_28; uVar9 = uVar9 + 1) {
        if (local_14 < *puVar3) {
          local_14 = *puVar3;
        }
        uVar11 = *puVar3;
        puVar3 = puVar3 + 1;
        uVar10 = uVar10 + uVar11;
      }
    }
    param_1[0x12a] = local_1c;
    param_1[0x129] = uVar8;
    param_1[0x126] = uVar10 / uVar9;
    if ((param_2 & 0x200) == 0) {
      if (param_3 == 0xffffffff) {
        if (param_1[0x100] == 0) {
          param_3 = 0x3000;
        }
        else {
          param_3 = param_1[0x129];
        }
        if (uVar10 >> 2 < param_3) {
          param_3 = uVar10 >> 2;
        }
        if (param_3 < 0x3000) {
          param_3 = 0x3000;
        }
      }
      param_3 = param_3 + 0xfff & 0xfffff000;
      if (param_3 < 0x2000) {
        param_3 = 0x2000;
      }
      if (param_3 < (uVar10 * 4) / 5) {
        param_1[0x110] = param_3;
        param_1[0xe6] = local_14;
        if (param_3 != 0) {
          iVar5 = param_3 + 0x1000;
          uVar10 = param_1[0x117] + iVar5;
          param_1[0x117] = uVar10;
          if ((uint)param_1[0x127] < uVar10) {
            param_1[0x127] = uVar10;
          }
          iVar5 = FUN_00402c30(uVar10,iVar5,iVar5);
          param_1[0x10b] = iVar5;
          param_1[0x10d] = iVar5;
          param_1[0x10e] = iVar5;
          if (iVar5 == 0) goto LAB_00404bd7;
          param_1[0x10c] = iVar5 + param_1[0x110];
        }
      }
      else {
        param_2 = param_2 | 0x200;
        param_1[0xe6] = uVar10;
      }
    }
    else {
      param_1[0xe6] = uVar10;
    }
    iVar5 = param_1[0xe6] + 8;
    uVar10 = param_1[0x127];
    uVar8 = param_1[0x117] + iVar5;
    param_1[0x117] = uVar8;
    if (uVar10 < uVar8) {
      param_1[0x127] = uVar8;
    }
    iVar5 = FUN_00402c30(uVar10,iVar5,iVar5);
    param_1[0xeb] = iVar5;
    if (iVar5 != 0) {
      param_1[0x111] = param_1[0xea];
      if ((param_2 & 0x200) == 0) {
        local_28 = param_1[0xea] & 0xfff;
        uVar6 = extraout_ECX_05;
        if (local_28 != 0) {
          ReadFile((HANDLE)param_1[0xe5],(LPVOID)param_1[0x10b],0x1000 - local_28,&local_28,
                   (LPOVERLAPPED)0x0);
          param_1[0x10e] = local_28 + param_1[0x10b];
          param_1[0x10f] = local_28;
          uVar6 = extraout_ECX_08;
        }
        if ((*(byte *)((int)param_1 + 0x385) & 2) == 0) {
          param_1[0xec] = param_1[0xeb];
          FUN_004059b0(uVar6,(undefined4 *)param_1[0xeb]);
          uVar6 = extraout_ECX_09;
        }
      }
      else {
        FUN_004059b0(extraout_ECX_05,(undefined4 *)param_1[0xeb]);
        uVar6 = extraout_ECX_06;
        if ((param_2 & 0x1000) == 0) {
          CloseHandle((HANDLE)param_1[0xe5]);
          uVar6 = extraout_ECX_07;
        }
        param_1[0xe5] = -1;
        param_1[0xec] = param_1[0xeb];
      }
      param_1[0xed] = -1;
      FUN_004053e0(uVar6);
      param_1[0x108] = -1;
      param_1[0xe1] = param_2 & 0xffc01fff;
      uVar10 = extraout_ECX_10;
      uVar8 = extraout_EDX_01;
      while ((param_2 & 0xfe000) != 0) {
        uVar8 = 0x2000;
        bVar1 = 0;
        do {
          if ((uVar8 & param_2) != 0) {
            uVar10 = param_2 & ~uVar8;
            param_2 = uVar10;
            goto LAB_00404fe0;
          }
          bVar1 = bVar1 + 1;
          uVar8 = uVar8 * 2;
        } while (bVar1 < 7);
        bVar1 = 0xff;
LAB_00404fe0:
        local_28 = (DWORD)bVar1;
        iVar5 = FUN_00405d70(uVar10,0x74);
        param_1[local_28 + 0x101] = iVar5;
        uVar10 = extraout_ECX_11;
        uVar8 = local_28;
        if (param_1[local_28 + 0x101] != 0) {
          uVar10 = FUN_00405160(extraout_ECX_11,(byte)local_28);
          if ((char)uVar10 == '\0') {
            FUN_00402c10();
            param_1[0x117] = param_1[0x117] + -0x74;
            param_1[local_28 + 0x101] = 0;
            uVar10 = extraout_ECX_12;
            uVar8 = extraout_EDX_03;
          }
          else {
            uVar10 = local_28 + 0xd;
            param_1[0xe1] = param_1[0xe1] | 1 << ((byte)uVar10 & 0x1f);
            uVar8 = extraout_EDX_02;
          }
        }
      }
      param_1[0xff] = -1;
      uVar12 = CONCAT44(uVar8,param_2) & 0xffffffff00000100;
      while ((int)uVar12 != 0) {
        uVar12 = FUN_00405c60(uVar10,(int)(uVar12 >> 0x20));
        uVar10 = extraout_ECX_13;
      }
      uVar10 = param_2 & 0x300000;
      if (uVar10 < 0x200000) {
        if (uVar10 != 0x100000) goto LAB_004050c0;
        uVar10 = param_1[5] & 0xfffffff9U | 2;
      }
      else {
        if (0x200000 < uVar10) {
          if (uVar10 == 0x300000) {
            *(byte *)(param_1 + 5) = *(byte *)(param_1 + 5) & 0xf9;
          }
          goto LAB_004050c0;
        }
        uVar10 = param_1[5] & 0xfffffff9U | 4;
      }
      param_1[5] = uVar10;
LAB_004050c0:
      uVar10 = param_1[5] & 6;
      if (1 < uVar10) {
        if (uVar10 < 3) {
          *(byte *)((int)param_1 + 0x386) = *(byte *)((int)param_1 + 0x386) | 0x10;
        }
        else if (uVar10 == 4) {
          *(byte *)((int)param_1 + 0x386) = *(byte *)((int)param_1 + 0x386) | 0x20;
        }
      }
      if ((*(byte *)((int)param_1 + 0x386) & 0x30) != 0) {
        param_1[2] = param_1[2] * 2;
      }
      DVar4 = timeGetTime();
      param_1[0x11c] = DVar4 - local_24;
      iVar5 = param_1[0x115];
      param_1[0x115] = 0;
      param_1[0x113] = param_1[0x113] + iVar5;
      param_1[0x112] = param_1[0x112] + param_1[0x114];
      param_1[0x11d] = param_1[0x113];
      return param_1;
    }
    if (param_1[0x10b] != 0) {
      FUN_00402c10();
    }
  }
LAB_00404bd7:
  FUN_00402c10();
  FUN_00402c10();
LAB_00404a15:
  if ((param_2 & 0x1000) == 0) {
    CloseHandle((HANDLE)param_1[0xe5]);
  }
  if ((param_2 & 0x2000000) != 0) {
    return (int *)0x0;
  }
  FUN_00402c10();
  return (int *)0x0;
}

