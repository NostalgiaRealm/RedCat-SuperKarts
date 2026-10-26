/*
 * FUN_0046d36c at 0046d36c
 * undefined __register FUN_0046d36c(int * param_1)
 * Address ranges: 0046d36c-0046d5b6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046d36c(int *param_1)

{
  char cVar1;
  MCIERROR MVar2;
  int *piVar3;
  int iVar4;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  undefined4 *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined2 local_14;
  undefined *local_10;
  undefined *local_c;
  
  puStack_38 = &stack0xfffffffc;
  local_2c = (undefined4 *)0x0;
  puStack_3c = &LAB_0046d5b7;
  uStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_40;
  FUN_00402b54(&local_18,0x14,0);
  if (*(char *)((int)param_1 + 0x2c9) != '\0') {
    FUN_0046d5cc(param_1,extraout_EDX,extraout_ECX);
  }
  local_18 = 0;
  local_10 = (&PTR_DAT_0047c480)[*(byte *)(param_1 + 0xb7)];
  local_c = FUN_00403f94((undefined *)param_1[0xc0]);
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
  if ((char)param_1[0xb7] == '\0') {
    param_1[0xb4] = param_1[0xb4] | 0x200;
  }
  else {
    param_1[0xb4] = param_1[0xb4] | 0x2000;
  }
  if (*(char *)((int)param_1 + 0x307) != '\0') {
    param_1[0xb4] = param_1[0xb4] | 0x100;
  }
  local_18 = FUN_00445724(param_1);
  MVar2 = mciSendCommandA(0,0x803,param_1[0xb4],(DWORD_PTR)&local_18);
  param_1[0xbb] = MVar2;
  if (MVar2 == 0) {
    *(undefined1 *)((int)param_1 + 0x2c9) = 1;
    *(undefined2 *)((int)param_1 + 0x2da) = local_14;
    iVar4 = FUN_0046e4c4((int)param_1);
    param_1[0xba] = iVar4 / 10;
    FUN_0046e32c((int)param_1);
    if (*(char *)((int)param_1 + 0x2cf) != '\0') {
      FUN_0046e11c((int)param_1,(int *)param_1[0xbd]);
      FUN_0046e2d4((int)param_1,&local_28);
      param_1[0xbe] = local_20 - local_28;
      param_1[0xbf] = local_1c - local_24;
    }
    if (((char)param_1[0xb7] == '\x02') || ((char)param_1[0xb7] == '\v')) {
      FUN_0046e0e0((int)param_1,10);
    }
    *(undefined2 *)((int)param_1 + 0x28e) = 0x18;
    if ((char)param_1[0xb3] != '\0') {
      *(ushort *)((int)param_1 + 0x28e) = *(ushort *)((int)param_1 + 0x28e) | 0x60;
    }
    if (*(char *)((int)param_1 + 0x2cb) != '\0') {
      *(ushort *)((int)param_1 + 0x28e) = *(ushort *)((int)param_1 + 0x28e) | 1;
    }
    if (*(char *)((int)param_1 + 0x2ce) != '\0') {
      *(ushort *)((int)param_1 + 0x28e) = *(ushort *)((int)param_1 + 0x28e) | 0x80;
    }
    if (*(char *)((int)param_1 + 0x2cd) != '\0') {
      *(ushort *)((int)param_1 + 0x28e) = *(ushort *)((int)param_1 + 0x28e) | 0x100;
    }
    cVar1 = FUN_0046e554((int)param_1);
    if (cVar1 == '\x02') {
      FUN_00403088(param_1,0,extraout_ECX_00);
    }
    FUN_0046c69c(param_1);
  }
  else {
    FUN_0046e620((int)param_1,(int *)&local_2c);
    piVar3 = FUN_0040ac64((int *)&DAT_0046bd88,'\x01',local_2c);
    FUN_00403604(piVar3);
  }
  *in_FS_OFFSET = uStack_40;
  puStack_38 = &LAB_0046d5be;
  puStack_3c = (undefined1 *)0x46d5b6;
  FUN_00403b50((int *)&local_2c);
  return;
}

