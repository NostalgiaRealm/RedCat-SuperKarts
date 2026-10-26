/*
 * FUN_00443028 at 00443028
 * bool __register FUN_00443028(int * param_1, undefined4 * param_2)
 * Address ranges: 00443028-004430b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00443028(int *param_1,undefined4 *param_2)

{
  HWND pHVar1;
  HWND pHVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  int local_1c;
  int local_18;
  int local_14 [2];
  
  pHVar1 = (HWND)FUN_00445724(param_1);
  pHVar2 = GetCapture();
  if (pHVar1 == pHVar2) {
    iVar3 = 0;
    if ((DAT_0047b9b8 != 0) && (param_1 == *(int **)(DAT_0047b9b8 + 0x24))) {
      iVar3 = DAT_0047b9b8;
    }
  }
  else {
    cVar5 = '\0';
    FUN_00406c20(param_2[2],local_14);
    iVar3 = FUN_00442f94((int)param_1,local_14,0,cVar5);
  }
  if (iVar3 != 0) {
    local_1c = (int)*(short *)(param_2 + 2) - *(int *)(iVar3 + 0x30);
    local_18 = (int)*(short *)((int)param_2 + 10) - *(int *)(iVar3 + 0x34);
    uVar4 = FUN_00406c34((undefined2 *)&local_1c);
    uVar4 = FUN_004405f0(iVar3,*param_2,param_2[1],uVar4);
    param_2[3] = uVar4;
  }
  return iVar3 != 0;
}

