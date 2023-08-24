
- OTP
    One-time password
    a form of multi-factor authentication (MFA) 

    All of these algorithms use two inputs to generate the OTP code: a seed and a moving factor. 
- UX
    User experience

- HOTP
    The “H” in HOTP stands for Hash-based Message Authentication Code (HMAC).
    Put in layman’s terms, HMAC-based One-time Password algorithm (HOTP) is an **event-based OTP** where the moving factor in each code is based on a counter.

- TOTP
    Time-based One-time Password (TOTP) is a time-based OTP. The seed for TOTP is static, just like in HOTP, but the moving factor in a TOTP is **time-based** rather than counter-based.
