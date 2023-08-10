#pragma region Fraction

#ifndef _FRACTION
#define _FRACTION 1

template <typename _Tp>
class fraction
{
public:
    _Tp numerator;
    _Tp denominator;

private:
    void normalize()
    {
        _Tp GCD = gcd(numerator, denominator);
        if (GCD)
        {
            numerator /= GCD;
            denominator /= GCD;
        }
        if (denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
    }

public:
    fraction<_Tp>& operator= (const fraction& _val)
    {
        numerator = _val.numerator;
        denominator = _val.denominator;
        return *this;
    }

    template <typename _OtherTp>
    fraction<_Tp>& operator= (const _OtherTp& _val)
    {
        numerator = _val;
        denominator = 1;
        return *this;
    }

    fraction<_Tp>& operator+= (const fraction& _val)
    {
        const _Tp new_denominator = denominator / gcd(denominator, _val.denominator) * _val.denominator;
        numerator = numerator * (new_denominator / denominator) + _val.numerator * (new_denominator / _val.denominator);
        denominator = new_denominator;
        normalize();
        return *this;
    }
    
    template <typename _OtherTp>
    fraction<_Tp>& operator+= (const _OtherTp& _val)
    {
        numerator += _val * denominator;
        normalize();
        return *this;
    }

    template <typename _OtherTp>
    fraction<_Tp> operator+ (const _OtherTp& _val)
    {
        return fraction<_Tp>(*this) += _val;
    }

    fraction<_Tp>& operator-= (const fraction& _val)
    {
        const _Tp new_denominator = denominator / gcd(denominator, _val.denominator) * _val.denominator;
        numerator = numerator * (new_denominator / denominator) - _val.numerator * (new_denominator / _val.denominator);
        denominator = new_denominator;
        normalize();
        return *this;
    }
    
    template <typename _OtherTp>
    fraction<_Tp>& operator-= (const _OtherTp& _val)
    {
        numerator -= _val * denominator;
        normalize();
        return *this;
    }

    template <typename _OtherTp>
    fraction<_Tp> operator- (const _OtherTp& _val)
    {
        return fraction<_Tp>(*this) -= _val;
    }

    fraction<_Tp>& operator*= (const fraction& _val)
    {
        numerator *= _val.numerator;
        denominator *= _val.denominator;
        normalize();
        return *this;
    }

    template <typename _OtherTp>
    fraction<_Tp>& operator*= (const _OtherTp& _val)
    {
        numerator *= _val;
        normalize();
        return *this;
    }

    template <typename _OtherTp>
    fraction<_Tp> operator* (const _OtherTp& _val)
    {
        return fraction<_Tp>(*this) *= _val;
    }

    fraction<_Tp>& operator/= (const fraction& _val)
    {
        numerator *= _val.denominator;
        denominator *= _val.numerator;
        normalize();
        return *this;
    }

    template <typename _OtherTp>
    fraction<_Tp>& operator/= (const _OtherTp& _val)
    {
        denominator *= _val;
        normalize();
        return *this;
    }

    template <typename _OtherTp>
    fraction<_Tp> operator/ (const _OtherTp& _val)
    {
        return fraction<_Tp>(*this) /= _val;
    }

public:
    template <typename _OtherTp>
    friend _OtherTp& operator+= (_OtherTp& _other, const fraction& _val)
    {
        return _other += _val.numerator / _val.denominator;
    }

    template <typename _OtherTp>
    friend _OtherTp operator+ (const _OtherTp& _other, const fraction& _val)
    {
        return _other + _val.numerator / _val.denominator;
    }

    template <typename _OtherTp>
    friend _OtherTp& operator-= (_OtherTp& _other, const fraction& _val)
    {
        return _other -= _val.numerator / _val.denominator;
    }

    template <typename _OtherTp>
    friend _OtherTp operator- (const _OtherTp& _other, const fraction& _val)
    {
        return _other - _val.numerator / _val.denominator;
    }

    template <typename _OtherTp>
    friend _OtherTp& operator*= (_OtherTp& _other, const fraction& _val)
    {
        return (_other *= _val.numerator) /= _val.denominator;
    }

    template <typename _OtherTp>
    friend _OtherTp operator* (const _OtherTp& _other, const fraction& _val)
    {
        return _other * _val.numerator / _val.denominator;
    }

    template <typename _OtherTp>
    friend _OtherTp& operator/= (_OtherTp& _other, const fraction& _val)
    {
        return (_other *= _val.denominator) /= _val.numerator;
    }

    template <typename _OtherTp>
    friend _OtherTp operator/ (const _OtherTp& _other, const fraction& _val)
    {
        return _other * _val.denominator / _val.numerator;
    }

    friend fraction sqrt(const fraction& _fraction)
    {
        return fraction<_Tp>(sqrt(_fraction.numerator), sqrt(_fraction.denominator));
    }

    friend fraction pow(const fraction& _fraction, const _Tp& _power)
    {
        return fraction<_Tp>(pow(_fraction.numerator, _power), pow(_fraction.denominator, _power));
    }

    friend istream& operator>> (istream& _is, fraction& _fraction)
    {
        _fraction.denominator = 1;
        return _is >> _fraction.numerator;
    }

    friend ostream& operator<< (ostream& _os, const fraction& _fraction)
    {
        return _os << _fraction.numerator << '/' << _fraction.denominator;
    }

public:
    fraction()
        : numerator(0), denominator(1)
    {
    }

    fraction(const _Tp& _numerator, const _Tp& _denominator)
        : numerator(_numerator), denominator(_denominator)
    {
        normalize();
    }

    fraction(const fraction<_Tp>& _fraction)
        : numerator(_fraction.numerator), denominator(_fraction.denominator)
    {
    }
};

#endif /* _FRACTION */

#pragma endregion
