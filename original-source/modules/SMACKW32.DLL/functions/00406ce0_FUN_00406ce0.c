/*
 * FUN_00406ce0 at 00406ce0
 * longlong __fastcall FUN_00406ce0(undefined4 param_1, uint param_2)
 * Address ranges: 00406ce0-00406d42
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

longlong __fastcall FUN_00406ce0(undefined4 param_1,uint param_2)

{
  int iVar1;
  int *in_EAX;
  
  *(undefined1 *)((int)in_EAX + 0x29) = 0;
  if ((char)in_EAX[10] != '\0') {
    *(undefined1 *)(in_EAX + 10) = 0;
    (**(code **)(*(int *)in_EAX[1] + 0x48))((int *)in_EAX[1]);
    for (iVar1 = *in_EAX; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
      *(byte *)(iVar1 + 0x10) = *(byte *)(iVar1 + 0x10) | 1;
    }
    *in_EAX = 0;
    DAT_0040e878 = DAT_0040e878 + -1;
    if (DAT_0040e878 == 0) {
      timeKillEvent(DAT_004104d8);
      timeEndPeriod(0x1f);
    }
  }
  return (ulonglong)param_2 << 0x20;
}

