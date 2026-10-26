/*
 * FUN_0046e32c at 0046e32c
 * undefined __register FUN_0046e32c(int param_1)
 * Address ranges: 0046e32c-0046e4c0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046e32c(int param_1)

{
  MCIERROR MVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined1 auStack_3c [4];
  int local_38;
  undefined4 local_34;
  undefined1 local_30 [4];
  int local_2c [4];
  int local_1c [4];
  
  *(undefined4 *)(param_1 + 0x2d0) = 0x102;
  local_34 = 8;
  mciSendCommandA((uint)*(ushort *)(param_1 + 0x2da),0x80b,0x102,(DWORD_PTR)auStack_3c);
  *(char *)(param_1 + 0x2cb) = (char)local_38;
  if ((char)local_38 != '\0') {
    *(byte *)(param_1 + 0x2ca) = *(byte *)(param_1 + 0x2ca) | 4;
  }
  local_34 = 1;
  mciSendCommandA((uint)*(ushort *)(param_1 + 0x2da),0x80b,*(DWORD_PTR *)(param_1 + 0x2d0),
                  (DWORD_PTR)auStack_3c);
  *(char *)(param_1 + 0x2ce) = (char)local_38;
  if ((char)local_38 != '\0') {
    *(byte *)(param_1 + 0x2ca) = *(byte *)(param_1 + 0x2ca) | 8;
  }
  local_34 = 7;
  mciSendCommandA((uint)*(ushort *)(param_1 + 0x2da),0x80b,*(DWORD_PTR *)(param_1 + 0x2d0),
                  (DWORD_PTR)auStack_3c);
  *(char *)(param_1 + 0x2cd) = (char)local_38;
  if ((char)local_38 != '\0') {
    *(byte *)(param_1 + 0x2ca) = *(byte *)(param_1 + 0x2ca) | 2;
  }
  local_34 = 3;
  mciSendCommandA((uint)*(ushort *)(param_1 + 0x2da),0x80b,*(DWORD_PTR *)(param_1 + 0x2d0),
                  (DWORD_PTR)auStack_3c);
  *(char *)(param_1 + 0x2cf) = (char)local_38;
  if ((char)local_38 != '\0') {
    *(byte *)(param_1 + 0x2ca) = *(byte *)(param_1 + 0x2ca) | 0x10;
  }
  local_34 = 4;
  mciSendCommandA((uint)*(ushort *)(param_1 + 0x2da),0x80b,*(DWORD_PTR *)(param_1 + 0x2d0),
                  (DWORD_PTR)auStack_3c);
  if ((((local_38 == 0x207) || (local_38 == 0x208)) || (local_38 == 0x203)) || (local_38 == 0x201))
  {
    *(undefined1 *)(param_1 + 0x2cc) = 1;
  }
  if (*(char *)(param_1 + 0x2cc) != '\0') {
    *(byte *)(param_1 + 0x2ca) = *(byte *)(param_1 + 0x2ca) | 1;
  }
  *(undefined4 *)(param_1 + 0x2d0) = 0x20000;
  MVar1 = mciSendCommandA((uint)*(ushort *)(param_1 + 0x2da),0x843,0x20000,(DWORD_PTR)local_30);
  *(MCIERROR *)(param_1 + 0x2ec) = MVar1;
  piVar3 = local_2c;
  piVar4 = local_1c;
  for (iVar2 = 4; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  *(int *)(param_1 + 0x2f8) = local_1c[2] - local_1c[0];
  *(int *)(param_1 + 0x2fc) = local_1c[3] - local_1c[1];
  return;
}

