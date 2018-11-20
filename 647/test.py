def palindrome(string):
    palindromes = list()
    for start in range(len(string)):
        for end in range(1, len(string)+1):
            maybe_palindrome = string[start:end]
            if maybe_palindrome:
                if maybe_palindrome == ''.join(reversed(maybe_palindrome)):
                    palindromes.append(maybe_palindrome)
    return list(set(palindromes))

def main():
    arr = "aaa"
    pals = palindrome(arr)
    print(pals)

if __name__ == "__main__":
    main()

