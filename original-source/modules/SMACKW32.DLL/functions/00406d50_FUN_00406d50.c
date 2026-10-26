/*
 * FUN_00406d50 at 00406d50
 * undefined4 __fastcall FUN_00406d50(undefined4 param_1, int param_2)
 * Address ranges: 00406d50-00406e25
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __fastcall FUN_00406d50(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  uint uVar3;
  
  *(undefined4 *)(param_2 + 0x1c) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0;
  *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) & 0xfe;
  uVar3 = timeGetTime();
  *(int *)(param_2 + 8) =
       (int)(((ulonglong)*(uint *)(param_2 + 4) * 1000) / (ulonglong)(uint)in_EAX[9]);
  iVar1 = *in_EAX;
  if (iVar1 == 0) {
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + uVar3;
    *in_EAX = param_2;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x18);
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar1 + 0x18);
      iVar2 = *(int *)(iVar1 + 0x18);
    }
    *(int *)(iVar1 + 0x18) = param_2;
    if (uVar3 < *(uint *)(iVar1 + 8)) {
      uVar3 = *(uint *)(iVar1 + 8);
    }
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + uVar3;
  }
  if ((char)in_EAX[10] == '\0') {
    (**(code **)(*(int *)in_EAX[1] + 0x30))((int *)in_EAX[1],0,0,1);
    DAT_0040e878 = DAT_0040e878 + 1;
    if (DAT_0040e878 == 1) {
      timeBeginPeriod(0x1f);
      DAT_004104d8 = timeSetEvent(0x1f,0,_TimerFunc_20,0,1);
    }
    *(undefined1 *)(in_EAX + 10) = 1;
  }
  return 0;
}

