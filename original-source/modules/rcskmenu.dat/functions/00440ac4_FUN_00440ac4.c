/*
 * FUN_00440ac4 at 00440ac4
 * char __register FUN_00440ac4(int * param_1, int * param_2, int * param_3)
 * Address ranges: 00440ac4-00440b5e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char FUN_00440ac4(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  char cVar2;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_20 = *param_2;
  local_1c = *param_3;
  uVar1 = FUN_004404bc(param_1,&local_20,&local_1c);
  if ((char)uVar1 != '\0') {
    local_18 = local_20;
    local_14 = local_1c;
    if ((((char)param_1[0x13] == '\0') ||
        (((uVar1 = FUN_00440450(param_1,&local_18,&local_14), (char)uVar1 != '\0' &&
          (local_18 == local_20)) && (local_14 == local_1c)))) ||
       (uVar1 = FUN_004404bc(param_1,&local_18,&local_14), (char)uVar1 != '\0')) {
      cVar2 = '\x01';
    }
    else {
      cVar2 = '\0';
    }
    if (cVar2 != '\0') {
      *param_2 = local_18;
      *param_3 = local_14;
    }
    return cVar2;
  }
  return '\0';
}

