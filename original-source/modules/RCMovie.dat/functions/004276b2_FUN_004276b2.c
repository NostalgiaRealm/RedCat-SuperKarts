/*
 * FUN_004276b2 at 004276b2
 * undefined4 __cdecl FUN_004276b2(uint * param_1, int param_2)
 * Address ranges: 004276b2-00427838
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_004276b2(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  uint *lpName;
  undefined1 *puVar5;
  int *piVar6;
  bool bVar7;
  
  if (param_1 == (uint *)0x0) {
    return 0xffffffff;
  }
  puVar1 = FUN_00427a18(param_1,0x3d);
  if (puVar1 == (uint *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == puVar1) {
    return 0xffffffff;
  }
  bVar7 = *(char *)((int)puVar1 + 1) == '\0';
  if (DAT_0043e2e8 == DAT_0043e2ec) {
    DAT_0043e2e8 = FUN_00427891(DAT_0043e2e8);
  }
  if (DAT_0043e2e8 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_0043e2f0 == (undefined4 *)0x0)) {
      if (bVar7) {
        return 0;
      }
      DAT_0043e2e8 = _malloc(4);
      if (DAT_0043e2e8 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_0043e2e8 = 0;
      if (DAT_0043e2f0 == (undefined4 *)0x0) {
        DAT_0043e2f0 = _malloc(4);
        if (DAT_0043e2f0 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_0043e2f0 = 0;
      }
    }
    else {
      iVar2 = FUN_0042712b();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_0043e2e8;
  iVar2 = FUN_00427839((uchar *)param_1,(int)puVar1 - (int)param_1);
  if ((iVar2 < 0) || (*piVar3 == 0)) {
    if (bVar7) {
      return 0;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    piVar3 = FUN_004278f8(piVar3,(uint *)(iVar2 * 4 + 8));
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar3[iVar2] = (int)param_1;
    piVar3[iVar2 + 1] = 0;
  }
  else {
    if (!bVar7) {
      piVar3[iVar2] = (int)param_1;
      goto LAB_004277e6;
    }
    piVar6 = piVar3 + iVar2;
    FUN_0041fd93((LPVOID)piVar3[iVar2]);
    for (; *piVar6 != 0; piVar6 = piVar6 + 1) {
      iVar2 = iVar2 + 1;
      *piVar6 = piVar6[1];
    }
    piVar3 = FUN_004278f8(piVar3,(uint *)(iVar2 << 2));
    if (piVar3 == (int *)0x0) goto LAB_004277e6;
  }
  DAT_0043e2e8 = piVar3;
LAB_004277e6:
  if (param_2 != 0) {
    sVar4 = _strlen((char *)param_1);
    lpName = _malloc(sVar4 + 2);
    if (lpName != (uint *)0x0) {
      FUN_0041f7a0(lpName,param_1);
      puVar5 = (undefined1 *)(((int)lpName - (int)param_1) + (int)puVar1);
      *puVar5 = 0;
      SetEnvironmentVariableA((LPCSTR)lpName,(LPCSTR)(~-(uint)bVar7 & (uint)(puVar5 + 1)));
      FUN_0041fd93(lpName);
    }
  }
  return 0;
}

