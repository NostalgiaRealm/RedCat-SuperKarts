/*
 * FUN_0046d87c at 0046d87c
 * undefined FUN_0046d87c(void)
 * Address ranges: 0046d87c-0046d90c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046d87c(int *param_1,undefined4 param_2,int param_3)

{
  MCIERROR MVar1;
  int iStack_8;
  
  iStack_8 = param_3;
  FUN_0046d260((int)param_1);
  param_1[0xb4] = 0;
  if (*(char *)((int)param_1 + 0x2d6) == '\0') {
    param_1[0xb4] = 2;
  }
  else {
    if ((char)param_1[0xb5] != '\0') {
      param_1[0xb4] = 2;
    }
    *(undefined1 *)((int)param_1 + 0x2d6) = 0;
  }
  if (*(char *)((int)param_1 + 0x2d7) != '\0') {
    if (*(char *)((int)param_1 + 0x2d5) != '\0') {
      param_1[0xb4] = param_1[0xb4] | 1;
    }
    *(undefined1 *)((int)param_1 + 0x2d7) = 0;
  }
  iStack_8 = FUN_00445724(param_1);
  MVar1 = mciSendCommandA((uint)*(ushort *)((int)param_1 + 0x2da),0x808,param_1[0xb4],
                          (DWORD_PTR)&iStack_8);
  param_1[0xbb] = MVar1;
  return;
}

